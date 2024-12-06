#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<vector<long long>> dp(n, vector<long long>(n, 0));

	for (int len = 1; len <= n; len++) {
		for (int i = 0; i + len - 1 < n; i++) {
			int j = i + len - 1;
			// [i, j]
			// i = 0, j = 1
			// len -> длинна отрезка [i, j]
			// n - len -> сколько чисел мы удалили
			// номер хода = сколько чисел мы удалили + 1
			int cnt = n - len + 1;
			if (cnt % 2 == 1) {
				// first's player move
				if (len == 1) {
					dp[i][j] = a[i];
				}
				else {
					dp[i][j] = max(a[i] + dp[i + 1][j], a[j] + dp[i][j - 1]);
				}
			}
			else {
				// second's player move
				if (len > 1) {
					dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]);
				}
			}
		}
	}
	cout << dp[0][n - 1] << '\n';
}
