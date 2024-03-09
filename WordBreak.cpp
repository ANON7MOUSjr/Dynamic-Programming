// https://leetcode.com/problems/word-break/description/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}

bool wordBreak(string s, vector<string>& wordDict) {
	int n = s.size();
	int maxLength = 0;
	map<string, int> mp;
	for (auto &i : wordDict) {
		mp[i] = 1;
		int curLength = i.size();
		if (curLength > maxLength) maxLength = curLength;
	}
	vector<bool> dp(n + 1);
	dp[0] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = i - 1; j >= 0; --j) {
			if (i - j > maxLength) break;
			string a = s.substr(j, i - j);
			if (dp[j] && mp.find(a) != mp.end()) {
				dp[i] = 1;
				break;
			}
		}
	}
	return dp[n];
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t;	cin >> t;
	while (t--) {
		string s = "applepenapple";
		vector<string> wordDict = {"apple", "pen"};
		cout << wordBreak(s, wordDict);
	}
	return 0;
}
