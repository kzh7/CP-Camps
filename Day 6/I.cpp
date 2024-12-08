#include <bits/stdc++.h>

using namespace std;

const int N = (int)2e5 + 7;

int n, m;
vector<pair<int, int>> g[N];
int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int v, u, len;
    cin >> v >> u >> len;
    g[v].push_back({u, len}); // orange 
    g[v].push_back({u + n, len / 2}); // blue
  }
  /*
    dijkstra part
  */
  cout << dist[2 * n];
  return 0;
}
