#include <bits/stdc++.h>

using namespace std;


void problem1() {
	int n;
	cin >> n;
	vector<int> dp(n + 1);

	dp[0] = 1;
	dp[1] = 1;
	// base case

	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	cout << dp[n] << endl;
}

void problem2() {
	int n;
	cin >> n;
	vector<int> cost(n + 1);
	vector<int> dp(n + 1);

	for (int i = 1; i <= n; i++) {
		cin >> cost[i];
	}

	dp[0] = 0;
	dp[1] = cost[1];
	// base case

	for (int i = 2; i <= n; i++) {
		dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
	}

	/*
		pos: 0 1 2 3 4 
		dp:  0 2 1 4 5

		cur_pos = 4
	*/
	vector<int> ans;
	int pos = n;
	// recover answer
	while (pos > 0) { // pos = 0
		ans.push_back(pos); // ans = {4, 2}
		// if pos == 1 -> dp[1 - 2]
		if (pos == 1 || dp[pos - 1] < dp[pos - 2]) {
			pos = pos - 1;
		}
		else {
			pos = pos - 2;
		}
	}
	ans.push_back(0);
	cout << dp[n] << endl;
	reverse(ans.begin(), ans.end());
	for (int i = 0; i < (int)ans.size(); i++) {
		cout << ans[i] << ' ';
	}
	// for (auto it : ans) 
	// 	cout << it << ' ';
	// }
	cout << endl;
}
/*
	pos: 0 2 4
*/

void problem3() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

	dp[1][1] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i == 1 && j == 1) {
				continue;
			}
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}
	cout << dp[n][m] << endl;
}

void problem4() {
	int n;
	const int mod = (int)1e9 + 7;
	cin >> n;
	vector<int> dp(n + 1, 0);
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		/*
			// dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3] + dp[i - 4] + dp[i - 5] + dp[i - 6];
			
			if (i - 1 >= 0) dp[i] += dp[i - 1];
			if (i - 2 >= 0) dp[i] += dp[i - 2];
			if (i - 3 >= 0) dp[i] += dp[i - 3];
			if (i - 4 >= 0) dp[i] += dp[i - 4];
			if (i - 5 >= 0) dp[i] += dp[i - 5];
			if (i - 6 >= 0) dp[i] += dp[i - 6];
		*/ 
		for (int j = 1; j <= 6; j++) {
			if (i - j >= 0) {
				dp[i] += dp[i - j];
				dp[i] = dp[i] % mod;
			}
		}
	}
	cout << dp[n] << endl;
}

void problem4() {
	int n, x;
	const int inf = (int)1e9 + 7;
	cin >> n >> x;
	vector<int> coin(n + 1);
	vector<int> dp(x + 1, inf);
	for (int i = 1; i <= n; i++) {
		cin >> coin[i];
	}
	dp[0] = 0;
	for (int i = 1; i <= x; i++) {
		for (int j = 1; j <= n; j++) {
			if (i - coin[j] >= 0) {
				dp[i] = min(dp[i], dp[i - coin[j]] + 1);
			}
		}
	}
	cout << dp[n] << endl;
}


int main() {
	// problem1();
	// problem2();
	// problem3();
	problem4();
}
