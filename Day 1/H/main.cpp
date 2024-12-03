#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 7;

int n;
int a[N], b[N];
long long int ans;
void merge(int l, int r) {
	if (l == r) {
		return;
	}
	int mid = (l + r) / 2;
	merge(l, mid);
	merge(mid + 1, r);

	int p1 = l, p2 = mid + 1;
	// left: [l, mid]
	// right: [mid + 1, r]
	for (int i = l; i <= r; i++) {
		if (p1 <= mid && (p2 > r || a[p1] <= a[p2])) {
			b[i] = a[p1++];
		}
		else {
			b[i] = a[p2++];
			ans += mid - p1 + 1;
		}
	}
	for (int i = l; i <= r; i++) {
		a[i] = b[i];
	}
}
void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	ans = 0;
	merge(1, n);
	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}
