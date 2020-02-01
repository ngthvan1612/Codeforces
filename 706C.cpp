///created: 12/Jun/2019 12:28:13

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

const int N = 1e5 + 5;
string a[N], ra[N];
int n, p[N][2][2] = {0}, c[N];
ll dp[N][2] = {0};

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> c[i];
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		ra[i] = a[i];
		reverse(ra[i].begin(), ra[i].end());
	}
	for (int i = 2; i <= n; ++i) {
		p[i][0][0] = (a[i - 1] <= a[i]);
		p[i][0][1] = (a[i - 1] <= ra[i]);
		p[i][1][0] = (ra[i - 1] <= a[i]);
		p[i][1][1] = (ra[i - 1] <= ra[i]);
	}
	for (int i = 2; i <= n; ++i)
		for (int j = 0; j < 2; ++j)
			dp[i][j] = 1e18 + 7;
	dp[1][0] = 0;
	dp[1][1] = c[1];
	for (int i = 2; i <= n; ++i) {
		if (p[i][0][0])
			dp[i][0] = min(dp[i][0], dp[i - 1][0]);
		if (p[i][0][1])
			dp[i][1] = min(dp[i][1], dp[i - 1][0] + c[i]);
		if (p[i][1][0])
			dp[i][0] = min(dp[i][0], dp[i - 1][1]);
		if (p[i][1][1])
			dp[i][1] = min(dp[i][1], dp[i - 1][1] + c[i]);
	}
	ll ans = min(dp[n][0], dp[n][1]);
	cout << (ans == 1e18 ? -1 : ans);
	return 0;
}
