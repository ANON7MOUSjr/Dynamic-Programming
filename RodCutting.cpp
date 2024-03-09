// https://leetcode.com/problems/minimum-cost-to-cut-a-stick/description/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}

int helper(int L, int R, vector<int> &cuts, int Left, int Right, vector<vector<int>> &dp) {
	if (Left > Right) return 0;
	if (dp[Left][Right] != -1) return dp[Left][Right];
	int cost = 1e9;
	for (int i = Left; i <= Right; ++i) {
		int cost_L = helper(L, cuts[i], cuts, Left, i - 1, dp);
		int cost_R = helper(cuts[i], R, cuts, i + 1, Right, dp);
		int cur = (R - L) + cost_L + cost_R;
		cost = min(cost, cur);
	}
	dp[Left][Right] = cost;
	return dp[Left][Right];
}
int minCost(int n, vector<int>& cuts) {
	int m = cuts.size();
	vector<vector<int>> dp(m + 1, vector<int>(m + 1, - 1));
	sort(cuts.begin(), cuts.end());
	int ans = helper(0, n, cuts, 0, m - 1, dp);
	return ans;
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t;	cin >> t;
	while (t--) {
		int n, m;	cin >> n >> m;
		vector<int> a(m);
		for (auto &i : a) cin >> i;
		cout << minCost(n, a) << endl;
	}
	return 0;
}
