#include <bits/stdc++.h>

using namespace std;

const int N = (int)1e3 + 7;

/*
  n -> # of nodes
  m -> # of edges

  v
  e
*/

int n, m;
bool mat[N][N]; // int m[N][N] -> m[a][b] = 10
vector<int> g[N]; // vector<pair<int, int>>
void storingEdges() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int a, b, cost;
    cin >> a >> b >> cost;

    // adjacency list
    g[a].push_back(b); //  g[a].push_back({b, cost});  
    g[b].push_back(a);

    // adjacency matrix
    mat[a][b] = mat[b][a] = 1;
    // m[a][b] = cost;
  }
}

bool was[N];

int id;
int vid[N];
void dfs(int v) {
  // cout << v << ' ';
  was[v] = 1;
  vid[v] = id;
  // for (int to : g[v]) { 
  //   if (!was[to]) {
  //     dfs(to);
  //   }
  // }
  for (int i = 0; i < (int)g[v].size(); i++) {
    int to = g[v][i];
    if (!was[to]) { // to is not visited yet
      dfs(to);
    }
  }
}
void example1() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int v, u;
    cin >> v >> u;
    g[v].push_back(u);
    g[u].push_back(v);
  }
  for (int i = 1; i <= n; i++) {
    if (!was[i]) {
      id++;
      dfs(i);
    }
  }

  int q;
  cin >> q;
  while (q--) {
    int x, y;
    cin >> x >> y;
    
    if (vid[x] == vid[y]) {
      cout << x << " and " << y << " are in the same component\n";
    }
    else {
      cout << x << " and " << y << " are not in the same component\n";
    }
  }
  
  // for (int i = 1; i <= n; i++) {
  //   cout << i << " lies in " << vid[i] << endl;
  // }
}
void example2() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int v, u;
    cin >> v >> u;
    g[v].push_back(u);
    g[u].push_back(v);

    mat[v][u] = 1;
    mat[u][v] = 1;
  }

  int s, f;
  cin >> s >> f;

  vector<int> dist(n + 1, -1);
  queue<int> q;
  
  q.push(s);
  dist[s] = 0;

  while (q.size()) { // q = {2, 5, 4}
    int v = q.front(); // v = 1
    q.pop();

    for (auto to : g[v]) { // g[1]
      if (dist[to] == -1) {
        dist[to] = dist[v] + 1;
        q.push(to);
      }
    }
  }

  cout << dist[f] << endl;
}

int main() {
  example2();
  return 0;
}
