/*
ID: aaronli2
TASK: theme
LANG: C++11
*/
#include <iostream>
#include <algorithm>
#include <fstream>
#include <cassert>
using namespace std;
constexpr auto N = 5100;
int n, f[N][N] = { 0 }, a[N] = { 0 }, ans(0);
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ofstream cout("theme.out");
    ifstream cin("theme.in");
    cin >> n;
    for (int i(1); i <= n; i++)
        cin >> a[i];
    for (int i(n); i > 0; i--) {
        assert(i < N&& i - 1 < N);
        a[i] -= a[i - 1];
    }
    for (int i(2); i <= n; i++)
        for (int j(i + ans + 1); j <= n; j++)
            if (a[i] == a[j])
                ans = max(ans, f[i][j] = min(j - i - 1, f[i - 1][j - 1] + 1));
    cout << ((ans > 3) ? (ans + 1) : 0) << '\n';
    return 0;
}
