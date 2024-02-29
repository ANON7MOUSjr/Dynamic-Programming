// https://www.codingninjas.com/studio/problems/printing-longest-increasing-subsequence_8360670?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}

vector<int> PrintLongestIncreasingSubsequence(vector<int> &a) {
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
	vector<int> v(ans);
	for (int i = n - 1; i >= 0; --i) {
		if (dp[i] == ans) {
			v[ans - 1] = a[i];
			ans--;
		}
	}
	return v;
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	vector<int> ans =  PrintLongestIncreasingSubsequence(a);
	for (auto i : ans) cout << i << " ";
	cout << "\n";

	return 0;
}
