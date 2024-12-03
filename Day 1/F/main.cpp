#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 7;

int n, q;
int a[N];
long long int pref[N];

void solve() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	reverse(a + 1, a + 1 + n);
	// sorted in decreasing order

	/*
						      
		a: 9  5  4   4   3   3 1 1
 pref: 9 14 18  22  25  28

	*/
	for (int i = 1; i <= n; i++) {
		pref[i] = pref[i - 1] + a[i];
	}
	while (q--) {
		int x;
		cin >> x;

		/*
		for (int i = 1; i <= n; i++) {
			if (pref[i] >= x) {
				ans = i;
				break;
			}
		}*/

		int l = 1, r = n, ans = -1;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (pref[mid] >= x) {
				ans = mid;
				r = mid - 1;
			}
			else {
				l = mid + 1;
			}
		}
		cout << ans << '\n';
	}
}
int main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}
