// https://www.codingninjas.com/studio/problems/1112624?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}

int maxIncreasingDumbbellsSum(vector<int> &a, int n) {
	// Write your code here
	vector<int> dp(n);
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		dp[i] = a[i];
		for (int j = 0; j < i; ++j) {
			if (a[j] < a[i]) dp[i] = max(dp[i], dp[j] + a[i]);
		}
		ans = max(dp[i], ans);
	}
	return ans;
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t;	cin >> t;
	while (t--) {
		int n;	cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) cin >> a[i];
		cout << maxIncreasingDumbbellsSum(a, n) << endl;
	}
	return 0;
}