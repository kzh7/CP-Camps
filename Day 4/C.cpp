#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

const int inf = (int)1e9 + 7;

// map<pair<int,int>, int> dp;
int calc(int a, int b) {
	if (a == b) {
		return 0;
	}
	// if (dp.co)
	int res = 1e9;
	// horizontal split
	for (int i = 1; i < a; i++) {
		res = min(res, calc(i, b) + calc(a - i, b) + 1);
	}
	// vertical split
	for (int i = 1; i < b; i++) {
		res = min(res, calc(a, i) + calc(a, b - i) + 1);
	}
	return res;
}

int main() {
	int a, b;
	cin >> a >> b;
	vector<vector<int>> dp(a + 1, vector<int>(b + 1, inf));
	for (int i = 1; i <= a; i++) {
		for (int j = 1; j <= b; j++) {
			if (i == j) {
				dp[i][j] = 0;
				continue;
			}

			// horizontal split
			for (int k = 1; k < i; k++) {
				dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
			}

			// vertical split
			for (int k = 1; k < j; k++) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
			}
		}
	}

	cout << dp[a][b];
}
