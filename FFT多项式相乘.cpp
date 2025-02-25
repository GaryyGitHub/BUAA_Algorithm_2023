#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
const double Pi = acos(-1.0);
struct Complex
{
    double x, y;
    Complex(double xx = 0, double yy = 0) { x = xx, y = yy; }
    double len2() const { return x * x + y * y; }
    Complex bar() const { return Complex(x, -y); }
} a[MAXN], b[MAXN];
Complex operator+(Complex a, Complex b) { return Complex(a.x + b.x, a.y + b.y); }
Complex operator-(Complex a, Complex b) { return Complex(a.x - b.x, a.y - b.y); }
// Complex operator*(double a, Complex b) { return Complex(a * b.x, a * b.y); }
// Complex operator*(Complex a, double b) { return Complex(a.x * b, a.y * b); }
Complex operator*(Complex a, Complex b) { return Complex(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x); }
// Complex operator/(Complex a, double b) { return Complex(a.x / b, a.y / b); }
// Complex operator/(Complex a, Complex b) { return a * b.bar() / b.len2(); }
int N, M;
int l, r[MAXN];
int limit = 1;
void FFT(Complex *A, int type)
{
    for (int i = 0; i < limit; i++)
        if (i < r[i])
            swap(A[i], A[r[i]]);              // 求出要迭代的序列
    for (int mid = 1; mid < limit; mid <<= 1) // 待合并区间的中点
    {
        Complex Wn(cos(Pi / mid), type * sin(Pi / mid)); // 单位根
        for (int R = mid << 1, j = 0; j < limit; j += R) // R是区间的右端点，j表示前已经到哪个位置了
        {
            Complex w(1, 0);                          // 幂
            for (int k = 0; k < mid; k++, w = w * Wn) // 枚举左半部分
            {
                Complex x = A[j + k], y = w * A[j + mid + k]; // 蝴蝶效应
                A[j + k] = x + y;
                A[j + mid + k] = x - y;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> N >> M; // 灵活改变！此处N和M为两多项式最高次数
    for (int i = 0; i <= N; i++)
        cin >> a[i].x;
    for (int i = 0; i <= M; i++)
        cin >> b[i].x;
    while (limit <= N + M)
        limit <<= 1, l++;
    // l=lg(N+M), limit=2^l
    // 这里只是多项式相乘如此实现，如果只是单纯的FFT，输入n，limit就是1<<n
    for (int i = 0; i < limit; i++)
        r[i] = (r[i >> 1] >> 1) | ((i & 1) << (l - 1));
    // 在原序列中 i 与 i/2 的关系是：i可以看做是i/2的二进制上的每一位左移一位得来
    // 那么在反转后的数组中就需要右移一位，同时特殊处理一下复数
    // 1表示从系数变为点值
    //-1表示从点值变为系数
    FFT(a, 1);
    FFT(b, 1);
    for (int i = 0; i <= limit; i++)
        a[i] = a[i] * b[i];
    FFT(a, -1);
    // 求逆DFT：1. a与y互换（板子里y就是a）2. wn^-1替换wn；3. 将计算结果每个元素除以n
    for (int i = 0; i <= N + M; i++)
        printf("%d ", (int)(a[i].x / limit + 0.5));
    return 0;
}