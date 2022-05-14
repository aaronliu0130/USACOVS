/*
ID: aaronli2
TASK: theme
LANG: C++11
*/
#include <iostream>
#include <algorithm>
#include <fstream>
#include <array>
using namespace std;
constexpr auto N(5000);
array<int, N> input = { 0 };
int main() {
    ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //ofstream cout("theme.out");
    //ifstream cin("theme.in");
    int n(0), ans(1);
    cin >> n;
    for (int i(0); i < n; i++) 
        cin >> input[i];
    int last, temp;
    for (int i(n - 2); i > 0; i--) {
        last = i, temp = i;
        for (int j(1); j <= i && last + j < n - 1; j++) {
            if (input[i - j] - input[i - j + 1] == input[n - 1 - j] - input[n - j])
                temp++;
            else
                last = i - j, temp = 1;
            ans = max(ans, temp);
        }
    }
    cout << ((ans < 5) ? 0 : ans) << '\n';
    return 0;
}
