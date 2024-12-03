#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 7;

int n, x;
pair<int, int> a[N];

void solve() {
	cin >> n >> x;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) {
		int l = i + 1, r = n;
		int target = x - a[i].first, ans = -1;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (a[mid].first > target) {
				r = mid - 1;
			}
			else if (a[mid].first < target) {
				l = mid + 1;
			}
			else {
				ans = mid;
				break;
			}
		}
		if (ans != -1) {
			cout << a[i].second << ' ' << a[ans].second << endl;
			return;
		}
	}
	cout << "IMPOSSIBLE";
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
}
