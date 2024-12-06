#include <bits/stdc++.h>

using namespace std;


void problem1() {
	int n;
	cin >> n;
	vector<int> a(n), dp(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			/*
				   v
				a: 1 1 1 2
			 dp: 1 1 1 
			*/
      // if (a[j] < a[i]) { incorrect
      //   dp[i] += dp[j];
      // }
			if (a[j] < a[i] && dp[j] + 1 > dp[i]) {
				dp[i] = dp[j] + 1;
			}
		}
	}
  // O(N^2)
  cout << *max_element(dp.begin(), dp.end()) << endl;
}
void problem2() {
	int n;
	cin >> n;
	vector<int> a(n), dp;
	for (int i = 0; i < n; i++) {
	  cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		// int pos = lower_bound(dp.begin(), dp.end(), a[i]) - dp.begin(); // >= a[i]
    auto it = lower_bound(dp.begin(), dp.end(), a[i]); // >= a[i]
    // dp = {0, 1, 2}
    //               ^
    if (it == dp.end()) {
      dp.push_back(a[i]);
    }
    else {
      // dp[pos] = a[i];
      *it = a[i];
    }
  }
  cout << dp.size() << endl;
  // O(n * log(n))
}

string s, t;

/*    
           i
  s = "naruto"
           j
  t = "minato"
*/

/*
  s[0..i]
  t[0..j]
*/

int dp[1000][1000];
bool was[1000][1000];
int calc(int i, int j) {

  // base case
  if (i < 0 || j < 0) {
    return 0;
  }

  if (was[i][j]) {
    return dp[i][j];
  }
  was[i][j] = 1;

  // cout << i << ' ' << j << endl;

  if (s[i] == t[j]) {
    /*
      "....." + s[i]
    */
    return dp[i][j] = calc(i - 1, j - 1) + 1;
  }
  /*
             i
  s = "acdcdxy"
            j
  t = "xyzcde"
  */
  return dp[i][j] = max(calc(i - 1, j), calc(i, j - 1));
}
void problem3() {
  cin >> s >> t;
  cout << calc(s.size() - 1, t.size() - 1) << endl;
}
void problem4() {
  cin >> s >> t;
  int n = s.size();
  int m = t.size();
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s[i - 1] == t[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      }
      else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + 1;
      }
    }
  }
  cout << dp[n][m] << endl;
}


int main() {
	problem4();

}
