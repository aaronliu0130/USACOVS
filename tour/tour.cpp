/*
 ID: aaronli2
 TASK: tour
 LANG: C++11
 */
#include<fstream>
#include<algorithm>
#include<map>
using namespace std;
#define MAXN 100
int main() {
	ios_base::sync_with_stdio(0);
	ofstream fout("tour.out");
	ifstream fin("tour.in");
	int n, v;
	bool flight[MAXN][MAXN] = { 0 };
	fin >> n >> v;
	{
		string s;
		map<string, int> order;
		for (int i(1); i <= n; i++) {
			fin >> s;
			order[s] = i;
		}
		string t;
		for (int i(1); i <= v; i++) {
			fin >> s >> t;
			flight[order[s]][order[t]] = 1, flight[order[t]][order[s]] = 1;
		}
	}
	int dp[MAXN][MAXN] = { 0 };
	dp[1][1] = 1;
	for (int i(1); i < n; i++)
		for (int j(i + 1); j <= n; j++)
			for (int k(1); k < j; k++)
				if (flight[j][k] && dp[i][k])
					dp[i][j] = dp[j][i] = max(dp[i][k] + 1, dp[i][j]);
	int ans(1);
	for (int i = 1; i <= n; i++)
		if (flight[i][n])
			ans = max(dp[i][n], ans);
	fout << ans << '\n';
}
