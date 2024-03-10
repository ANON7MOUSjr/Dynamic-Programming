// https://www.codingninjas.com/studio/problems/873266?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}

bool ispalin(int i, int j, string &str) {
	while (i < j) {
		if (str[i] != str[j]) return 0;
		++i, --j;
	}
	return 1;
}
int palindromePartitioning(string str) {
	// Write your code here
	int n = str.size();
	vector<int> dp(n + 1);
	for (int i = n - 1; i >= 0; --i) {
		int cost = n;
		for (int j = i; j < n; ++j) {
			if (ispalin(i, j, str)) {
				cost = min(cost, 1 + dp[j + 1]);
			}
		}
		dp[i] = cost;
	}
	return dp[0] - 1;
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t;	cin >> t;
	while (t--) {
		string s = "applepenapple";
		cout << palindromePartitioning(s);
	}
	return 0;
}
