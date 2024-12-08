#include <bits/stdc++.h>

using namespace std;

const int N = (int)1e3 + 7;
// R, D, L, U
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const char dir[] = {'R', 'D', 'L', 'U'};

int n, m;
char a[N][N];
int dist[N][N];
char from[N][N];

bool check(int x, int y) {
  return 1 <= x && x <= n && 1 <= y && y <= m;
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> (a[i] + 1);
    // instead of below:
    // for (int j = 1; j <= m; j++) {
    //   cin >> a[i][j];
    // }
  }

  pair<int, int> start;
  pair<int, int> finish;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j] == 'A') {
        start = {i, j};
      }
      if (a[i][j] == 'B') {
        finish = {i, j};
      }

      dist[i][j] = -1;
    }
  }

  queue<pair<int, int>> q;
  q.push(start);
  dist[start.first][start.second] = 0;
  while (q.size()) {
    auto [x, y] = q.front();
    // int x = q.front().first;
    // int y = q.front().second;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (check(nx, ny) && a[nx][ny] != '#' && dist[nx][ny] == -1) {
        dist[nx][ny] = dist[x][y] + 1;
        from[nx][ny] = dir[i];
        q.push({nx, ny});
      }
    }
  }

  auto& [x, y] = finish;
  if (dist[x][y] == -1) {
    cout << "NO\n";
    exit(0);
  }
  cout << "YES\n" << dist[x][y] << '\n';
  string ans;
  while (finish != start) {
    char d = from[x][y];
    ans += d;
    if (d == 'L') y++;
    else if (d == 'R') y--;
    else if (d == 'U') x++;
    else x--;
  }
  reverse(ans.begin(), ans.end());
  cout << ans;
  return 0;
}
