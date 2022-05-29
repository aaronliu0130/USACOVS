/*
ID: aaronli2
TASK: fc
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;
struct point {
    double x, y;
}p[10005], s[10005];
inline double check(point a1, point a2, point b1, point b2) {
    return (a2.x - a1.x) * (b2.y - b1.y) - (b2.x - b1.x) * (a2.y - a1.y);
}
inline double distance(point p1, point p2) {
    return sqrt((p2.y - p1.y) * (p2.y - p1.y) + (p2.x - p1.x) * (p2.x - p1.x));
}
bool cmp(point p1, point p2) {
    double chk = check(p[1], p1, p[1], p2);
    if (chk > 0 || (!chk && distance(p[0], p1) < distance(p[0], p2)))
        return 1;
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ofstream cout("fc.out");
    ifstream cin("fc.in");
    int n; double mid; 
    cin >> n;
    for (int i(1); i <= n; i++) {
        cin >> p[i].x >> p[i].y;
        if (i > 1 && p[i].y < p[1].y) {
            mid = p[1].y; p[1].y = p[i].y; p[i].y = mid; mid = p[1].x; p[1].x = p[i].x; p[i].x = mid;
        }
    }
    sort(p + 2, p + n + 1, cmp); s[1] = p[1];
    int size(1);
    for (int i(2); i <= n; i++) {
        while (size > 1 && check(s[size - 1], s[size], s[size], p[i]) <= 0) size--;
        size++; s[size] = p[i];
    }
    s[size + 1] = p[1]; double ans(0);
    for (int i(1); i <= size; i++)
        ans += distance(s[i], s[i + 1]);
    cout << fixed << setprecision(2) << ans << '\n';
    return 0;
}
