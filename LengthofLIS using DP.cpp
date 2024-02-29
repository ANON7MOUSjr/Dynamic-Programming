// https://leetcode.com/problems/longest-increasing-subsequence/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}

int LengthofLongestIncreasingSubsequence(vector<int> &a) {
	int n = a.size();
	vector<int> dp(n, 1);
	int ans = dp[0];
	for (int cur = 1; cur < n; ++cur) {
		for (int prev = 0; prev < cur; ++prev) {
			if (a[prev] < a[cur]) {
				dp[cur] = max(dp[cur], 1 + dp[prev]);
			}
		}
		ans = max(dp[cur], ans);
	}
	return ans;
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	cout << LengthofLongestIncreasingSubsequence(a) << endl;
	return 0;
}
