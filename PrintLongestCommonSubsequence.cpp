// https://www.codingninjas.com/studio/problems/print-longest-common-subsequence_8416383?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}

string PrintLongestCommonSubsequence(string s1, string s2) {
	int n = s1.size();
	int m = s2.size();
	vector<vector<int>> dp(n + 1, vector<int>(m + 1));
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (s1[i - 1] == s2[j - 1]) {
				dp[i][j] = max(dp[i][j], 1 + dp[i - 1][j - 1]);
			}
			else {
				dp[i][j] = max({dp[i][j], dp[i - 1][j], dp[i][j - 1]});
			}
			ans = max(ans, dp[i][j]);
		}
	}
	string res;
	int i = n, j = m;
	while (i > 0 && j > 0) {
		if (s1[i - 1] == s2[j - 1]) {
			res += s1[i - 1];
			--i, --j;
		}
		else if (dp[i - 1][j] > dp[i][j - 1]) {
			--i;
		}
		else --j;
	}
	reverse(res.begin(), res.end());
	return res;
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string s1, s2;	cin >> s1 >> s2;
	cout << PrintLongestCommonSubsequence(s1, s2) << "\n";

	return 0;
}
