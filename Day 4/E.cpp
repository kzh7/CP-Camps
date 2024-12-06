using namespace std;
#include <iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<string>

void solve(string s) {
	int n = s.size();
    vector<long long> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
				if (s[i - 1] != '0') {
					dp[i] += dp[i - 1];
				}
				// 10 <= s[i]s[i + 1] <= 26
        int a = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
        if (10 <= a && a <= 26 && i >= 2) {
            dp[i] += dp[i - 2];
        }
    }
    cout << dp[n] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    string t;
    //getchar();
    while (cin >> t) {
			if (t == "0") {
				break;
			}
			solve(t);
    }
}
