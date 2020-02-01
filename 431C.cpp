///created: 21/Jun/2019 19:04:11

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
#define db(x) cerr << "debug: " << #x << " = " << x << '\n';
template<class __Ty> bool minimize(__Ty& a, __Ty b) {
	if (a > b) { a = b; return true; }
	return false;
}
template<class __Ty> bool maximize(__Ty& a, __Ty b) {
	if (a < b) { a = b; return true; }
	return false;
}

const int modulo = 1e9 + 7;

inline int add(int a, int b) {
	return (a + b) % modulo;
}

inline int sub(int a, int b) {
	return ((a - b) % modulo + modulo) % modulo;
}

int n, d, k;
int f[105][105][105][2] = {0};
int dp[105][2] = {0}, p[105][2] = {0};
///ans = f[1][n][true]

int calc_range(int l, int r, int t) {
	if (r < l) return 0;
	return add(sub(p[r][t], p[l][t]), dp[l][t]);
}

int dfs(int level, int edge, int sum, bool ok) {
	int& res = f[level][edge][sum][ok];
	if (~res) return res;
	if (sum == n)
		return res = ok;
	res = 0;
	for (int e = 1; e <= k && sum + e <= n; ++e)
		res = (res + dfs(level + 1, e, sum + e, ok || (e >= d))) % modulo;
	return res;
}

int main() {
	///ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k >> d;
	dp[0][0] = 1;
	p[0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		/**
		for (int z = i - min(d - 1, i); z <= i - 1; ++z)
			(dp[i][0] += dp[z][0]) %= modulo;

		for (int z = i - min(k, i); z <= i - d; ++z)
			(dp[i][1] += dp[z][0]) %= modulo;
					
		for (int z = i - min(k, i); z <= i - 1; ++z)
			(dp[i][1] += dp[z][1]) %= modulo;
		*/
		dp[i][0] = calc_range(i - min(d - 1, i), i - 1, 0);
		dp[i][1] = add(calc_range(i - min(k, i), i - d, 0), calc_range(i - min(k, i), i - 1, 1));
		p[i][0] = (p[i - 1][0] + dp[i][0]) % modulo;
		p[i][1] = (p[i - 1][1] + dp[i][1]) % modulo;
	}
	cout << dp[n][1];
	return 0;
}
