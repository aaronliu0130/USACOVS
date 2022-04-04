/*
ID: aaronli2
TASK: theme
LANG: C++11
*/
#include <iostream>
#include <algorithm>
#include <fstream>
#include <cassert>
#include <vector>
#include <array>
using namespace std;
constexpr auto N = 5002;
array<array<int, N>, N> f = { 0 };
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //ofstream cout("theme.out");
    //ifstream cin("theme.in");
    vector<int> a; int n, temp, ans(0);
    cin >> n;
    a.push_back(0);
    for (int i(1); i <= n; i++)
        cin >> temp, a.push_back(temp);
    for (int i(n); i > 0; i--) {
        assert(i < N&& i - 1 < N);
        a[i] -= a[i - 1];
    }
    for (int i(2); i <= n; i++)
        for (int j(i + ans + 1); j <= n; j++)
            if (a[i] == a[j])
                ans = max(ans, f[i][j] = min(j - i - 1, f[i - 1][j - 1] + 1));
    cout << ((ans > 3) ? (ans + 1) : 0) << '\n';
    while (1);
    return 0;
}
