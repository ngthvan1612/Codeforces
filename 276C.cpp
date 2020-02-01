///created: 12/Jun/2019 10:44:50

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

const int N = 2e5 + 5;
int a[N], l[N], r[N], id[N], dp[N], b[N];
int n, q;
ll f[N];

bool cmp(int i, int j) {
	return dp[i] > dp[j];
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		id[i] = i;
	}
	memset(dp, 0, sizeof dp);
	for (int i = 1; i <= q; ++i) {
		cin >> l[i] >> r[i];
		dp[l[i]]++;
		dp[r[i] + 1]--;
	}
	for (int i = 1; i <= n; ++i)
		dp[i] += dp[i - 1];
	ll ans = 0;
	sort(dp + 1, dp + 1 + n);
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; ++i)
		ans += 1LL * dp[i] * a[i];
	cout << ans;
	return 0;
}
