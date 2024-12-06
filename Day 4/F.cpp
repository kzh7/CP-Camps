#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	map<int, int> dp;
	for (int i = 0; i < n; i++) {
		/*
			a[i] = 6
			dp[6] = max(dp[6], dp[5] + 1);
		*/
		dp[a[i]] = dp[a[i] - 1] + 1;
	}
	int best = a[0];
	for (int i = 0; i < n; i++) {
		if (dp[a[i]] > dp[best]) {
			best = a[i];
		}
	}
	vector<int> ans;
	for (int i = n - 1; i >= 0; i--) {
		if (a[i] == best) {
			ans.push_back(i + 1);
			best--;
		}
	}
	cout << ans.size() << '\n';
	reverse(ans.begin(), ans.end());
	for (auto it : ans) {
		cout << it << ' ';
	}
	return 0;
}
