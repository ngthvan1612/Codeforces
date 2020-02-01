#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int dp[13][2][91], x[13], n;

int rec(int i, bool tight, int sum) {
	int &res = dp[i][tight][sum];
	if (~res) return res;
	if (i == n + 1) return res = (sum == 10);
	res = 0;
	for (int j = 0; j <= (tight ? x[i] : 9); ++j)
		res += rec(i + 1, tight && (j == x[i]), sum + j);
	return res;
}

int calc(ll c) {
	n = 0;
	while (c) { x[++n] = c % 10; c /= 10; }
	reverse(x + 1, x + 1 + n);
	memset(dp, -1, sizeof dp);
	return rec(1, 1, 0);
}

int main() {
	int k;
	cin >> k;
	ll l = 19, r = 1e11, ans = 0;
	while (l <= r) {
		ll mid = (l + r) / 2;
		if (calc(mid) >= k) { ans = mid; r = mid - 1; }
		else l = mid + 1;
	}
	cout << ans;
	return 0;
}
