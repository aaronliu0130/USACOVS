/*
ID: aaronli2
TASK: schlnet
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ifstream cin("schlnet.in");
    ofstream cout("schlnet.out");
    int n, i(1), j, k, map[101] = { 0 }; bool posi[101][101] = { 0 };
    cin >> n;
    for (; i < n + 1; i++)
        for (j = 1; j < n + 1; j++)
            for (k = 1; k < n + 1; k++)
                if (posi[j][i] && posi[i][k])posi[j][k] = 1;
    queue<int> q; int f, ans(0);
    for (i = 1; i < n + 1; i++) {
        if (map[i]) continue;
        map[i] = i; q.push(i);
        while (q.size()) {
            f = q.front(); q.pop();
            for (j = 1; j < n + 1; j++)
                if (!map[j] && (posi[j][f] || posi[f][j])) {
                    map[j] = i; q.push(j);
                }
        }
    }
    ans = i; int res(0), t[101] = { 0 }; bool d[101] = { 0 };
    for (i = 1; i < n + 1; i++, res++, t[map[i]]++) {
        if (d[i]) continue;
        for (j = 1; j < n + 1; j++)
            if (posi[j][i] && !posi[i][j]) {
                d[i] = 1; break;
            }
        if (d[i] == 1) continue;
        for (j = 1; j < n + 1; j++)
            if (posi[i][j])
                d[j] = 1;
    }
    for (auto a : d)a = 0;
    int b[101] = { 0 };
    for (i = 1; i < n + 1; i++) {
        if (d[i]) continue;
        f = 0;
        for (j = 1; j < n + 1; j++)
            if (posi[i][j]) f++;
        if (f == n) {
            d[i] = 1; continue;
        }
        for (j = 1; j < n + 1; j++)
            if (posi[i][j] && !posi[j][i]) {
                d[i] = 1; break;
            }
        if (d[i] == 1) continue;
        b[map[i]]++;
        for (j = 1; j < n + 1; j++)
            if (posi[i][j])d[j] = 1;
    }
    if (!b[1]) { 
        cout << "1\n0\n"; return 0;
    }
    for (i = 1; i < n + 1; i++)
        if (t[i])
            ans += (t[i] > b[i] ? t[i] : b[i]) - 1;
    cout << res << '\n' << ans << '\n';
    return 0;
}
