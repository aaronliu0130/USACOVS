/*
ID: aaronli2
TASK: snail
LANG: C++11
*/
#include <iostream>
#include <fstream>

using namespace std;

struct point {
    int x, y;
}s[120];
int a[120][120] = { 0 }, xx[4] = { 1,0,-1,0 }, yy[4] = { 0,1,0,-1 }, ans(0);
void dfs(int x, int y, int inc) {
    int max(inc), xy, yx;
    for (int i(0); i < 4; i++) {
        xy = x + xx[i], yx = y + yy[i];
        while (!a[xy][yx]) {
            s[++max] = point{ xy,yx }; a[xy][yx] = 2; xy += xx[i], yx += yy[i];
        }
        xy -= xx[i], yx -= yy[i];
        if (xy == x && yx == y) continue;
        ans = max > ans ? max : ans;
        if (a[xy + xx[i]][yx + yy[i]] != 2) dfs(xy, yx, max);
        while (max > inc) a[s[max].x][s[max--].y] = 0;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ofstream cout("snail.out");
    ifstream cin("snail.in");
    std::cout << "Hello World!\n";
    int n, m, sum; string c;
    cin >> n >> m;
    for (int i(0); i < m; i++) {
        cin >> c; sum = 0;
        for (int j(0); j <= 1; j++)
            sum = (sum << 1) + (sum << 3) + (c[i] - '0');
        a[c[1] - 'A' + 1][sum] = 1;
    }
    for (int i(1); i <= n; i++)
        a[0][i] = a[i][0] = a[n + 1][i] = a[i][n + 1] = 1;
    a[1][1] = 2; s[1] = point{ 1,1 };
    dfs(1, 1, 1);
    cout << ans << '\n';
}
