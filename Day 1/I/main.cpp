#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 7;

int n, t;
int a[N];

void solve() {
	cin >> n >> t;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	/*
		1 10^9
		10^9

		10^18

		ans = 8
	*/

	long long int l = 1, r = 1e18, ans = -1;
	while (l <= r) {
		long long int mid = (l + r) / 2;

		long long int sum = 0;
		for (int i = 1; i <= n; i++) {
			sum += mid / a[i];
			if (sum >= t) {
				break;
			}
		}

		if (sum >= t) {
			ans = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}

	cout << ans << endl;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	solve();
}
