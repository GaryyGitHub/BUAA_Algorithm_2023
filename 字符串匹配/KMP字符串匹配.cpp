#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;
int kmp[MAXN];
int lena, lenb, j;
char a[MAXN], b[MAXN];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> (a + 1);       // a为待匹配字符串
    cin >> (b + 1);       // b为模式串
    lena = strlen(a + 1); // la = n
    lenb = strlen(b + 1); // lb = m, m <= n
    // 处理kmp数组，模式串自己匹配自己
    for (int i = 2; i <= lenb; i++)
    {
        while (j && b[i] != b[j + 1]) // 若j为0，则不用回跳
            j = kmp[j];
        // 通过自己匹配自己来得出每一个点的kmp值
        if (b[i] == b[j + 1])
            j++;
        kmp[i] = j;
        // i+1失配后应该如何跳
    }
    j = 0;
    for (int i = 1; i <= lena; i++)
    { // j表示当前已经匹配完的模式串的最后一位的位置
        while (j > 0 && b[j + 1] != a[i])
            j = kmp[j]; // 如果失配，那么就不断向回跳，直到可以继续匹配
        if (b[j + 1] == a[i])
            j++; // 如果匹配成功，那么对应的模式串位置++
        if (j == lenb)
        {
            cout << i - lenb + 1 << '\n'; // 从小到大输出b在a中出现的位置
            j = kmp[j];                   // 继续匹配
        }
    }

    for (int i = 1; i <= lenb; i++)
        cout << kmp[i] << " ";
    /*此时的kmp[i]：满足下面条件的长度为i的非模式串s本身的前缀子串t：
    t既是s的前缀，又是s的后缀*/
    return 0;
}