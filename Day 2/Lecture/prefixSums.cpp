#include <iostream>

using namespace std;

const int N = (int)1e5 + 7;

int n;
int a[N];
long long int pref[N];

long long int sum(int l, int r) {
	// sum(l, r) = sum(1, r) - sum(1, l - 1)
	// O(1)
	return pref[r] - pref[l - 1];

	int res = 0;
	for (int i = l; i <= r; i++) {
		res += a[i];
	}
	// O(N)
	return res;
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
 		pref[i] = pref[i - 1] + a[i];
	}
	
	long long int ans = sum(1, 1);
	// O(N^2) -> O(N)
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			ans = max(ans, sum(i, j));
		}
	}
	/*
		r = 4
	*/
	long long int minPref = pref[0];
	for (int r = 1; r <= n; r++) {
		// for (int l = 1; l <= r; l++) {
		// 	minPref = min(minPref, pref[l - 1]);
		// 	// ans = max(ans, pref[r] - pref[l - 1]);
		// }
		minPref = min(minPref, pref[r - 1]);
		ans = max(ans, pref[r] - minPref);
	}
	// O(N)
	cout << ans;
	return 0;
}
/*
	pref[i] = a[1] + a[2] + ... + a[i]

	 i: 0  1  2   3  4
   a:   -4  2  -1  3
pref: 0 -4 -2  -3  0

	r = 4
  pref[4] - pref[l - 1] = 0 - (-4) = 4

		l  1 2 3 4
	sum:    

	sum(l, r) = pref[r] - pref[l - 1]

	for (int l = 1; l <= r; l++) {
	
	}

*/
