#include <bits/stdc++.h>

using namespace std;

const int N = (int)1e3 + 7;
// R, D, L, U
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int n, m;
char a[N][N];
bool was[N][N];

bool check(int x, int y) {
  return 1 <= x && x <= n && 1 <= y && y <= m;
}
void dfs(int x, int y) {
  was[x][y] = 1;
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (check(nx, ny) && a[nx][ny] == '.' && !was[nx][ny]) {
      dfs(nx, ny);
    }
  }
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

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j] == '.' && !was[i][j]) {
        dfs(i, j);
        ans++;
      }
    }
  }

  cout << ans;
  return 0;
}
