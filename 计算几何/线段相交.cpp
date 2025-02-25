#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
vector<pii> point;
// 判断线段p1p2和p3p4是否相交
int direction(pii pi, pii pj, pii pk)
{
    pii newpoint; //(pk-pi)x(pj-pi)为负，pk在pj的逆时针方向上
    int x1 = (pk.first - pi.first);
    int y1 = (pk.second - pi.second);
    int x2 = (pj.first - pi.first);
    int y2 = (pj.second - pi.second);
    return x1 * y2 - x2 * y1;
}
bool on_segment(pii pi, pii pj, pii pk)
{
    int xi = pi.first, yi = pi.second;
    int xj = pj.first, yj = pj.second;
    int xk = pk.first, yk = pk.second;
    if ((min(xi, xj) <= xk && xk <= max(xi, xj)) && (min(yi, yj) <= yk && yk <= max(yi, yj)))
        return true;
    else
        return false;
}
bool segments_intersect(pii p1, pii p2, pii p3, pii p4)
{ // 线段p1p2和p3p4是否相交
    int d1 = direction(p3, p4, p1);
    int d2 = direction(p3, p4, p2);
    int d3 = direction(p1, p2, p3);
    int d4 = direction(p1, p2, p4);
    if (((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0)) && ((d3 > 0 && d4 < 0) || (d3 < 0 && d4 > 0)))
        return true;
    else if (d1 == 0 && on_segment(p3, p4, p1))
        return true;
    if (d2 == 0 && on_segment(p3, p4, p2))
        return true;
    else if (d3 == 0 && on_segment(p1, p2, p3))
        return true;
    else if (d4 == 0 && on_segment(p1, p2, p4))
        return true;
    else
        return false;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    point.push_back({0, 5});
    point.push_back({1, 1});
    point.push_back({0, 5});
    point.push_back({5, 0});
    cout << segments_intersect(point[0], point[1], point[2], point[3]);
    return 0;
}