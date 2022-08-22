/*
 ID: aaronli2
 PROG: telecow
 LANG: C++17
 */
#include <fstream>
#include <cmath>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int N, M, s, t;
bool arr[201][201]{0};
int cost[201][201]{0}, temp[201][201]{0}, par[201]{0}, vis[201]{0};
vector<int> adj[201];

void reset() {
    for (int i = 0; i <= 2*N; i++)
        for (int j = 0; j <= 2*N; j++)
            cost[i][j] = temp[i][j];
}

bool bfs() {
    for (int i{0}; i <= 2*N; i++)
        vis[i] = 0, par[i] = -1;
    vis[s] = 1; int u, v;
    queue<int> q; q.push(s);
    while (!q.empty()) {
        u = q.front(); q.pop();
        for (int i{0}; i < adj[u].size(); i++) {
            v = adj[u][i];
            if (vis[v] || cost[u][v] <= 0) continue;
            vis[v] = 1, par[v] = u;
            if (v == t) break;
            q.push(v);
        }
        if (vis[t]) break;
    }
    if (!vis[t]) return 0;
    int cur{t};
    int flow = INT_MAX;
    while (par[cur] != -1)
        flow = min(flow, cost[par[cur]][cur]), cur = par[cur];
    cur = t;
    while (par[cur] != -1)
        cost[par[cur]][cur] -= flow, cost[cur][par[cur]] += flow, cur = par[cur];
    return flow;
}

int dinics() {
    int maxflow{0}, flow{1};
    while (flow) {
        flow = bfs();
        maxflow += flow;
    }
    return maxflow;
}

int main() {
    ofstream fout ("telecow.out");
    ifstream fin ("telecow.in");
    fin >> N >> M >> s >> t;
    s = 2*s, t = 2*t-1;
    for (int i{1}; i <= 2*N; i++)
        for (int j = 1; j <= 2*N; j++)
            arr[i][j] = 0, cost[i][j] = 0, temp[i][j] = 0;
    for (int i{1}; i <= N; i++) {
        adj[2*i-1].push_back(2*i);
        adj[2*i].push_back(2*i-1);
        cost[2*i-1][2*i] = 1;
        temp[2*i-1][2*i] = 1;
    }
    int u,v;
    for (int i{0}; i < M; i++) {
        fin >> u >> v;
        adj[2*u].push_back(2*v-1);
        adj[2*v].push_back(2*u-1);
        cost[2*u][2*v-1] = cost[2*v][2*u-1] = M;
        temp[2*u][2*v-1] = temp[2*v][2*u-1] = M;
    }
    vector<int> ans;
    int newf, maxflow = dinics();
    for (int i{1}; i <= N; i++) {
        if (2*i == s || 2*i-1 == t) continue;
        u = 2*i-1, v = 2*i;
        reset();
        cost[u][v] -= 1;
        newf = dinics();
        if (newf + 1 == maxflow) {
            ans.push_back(i);
            maxflow = newf;
            temp[u][v] = 0;
            if (!maxflow) break;
        }
        else cost[u][v] += 1;
    }
    fout << ans.size() << '\n';
    for (int i{0}; i < ans.size(); i++) {
        fout << ans[i];
        if (i != ans.size()-1) fout << " ";
    }
    if (ans.size()) fout << '\n';
    return 0;
}