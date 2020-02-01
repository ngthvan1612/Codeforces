///created: 2/Jun/2019 21:47:39

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int N = 5e5 + 5;

int n, a[N];
ll f[N], dp[N][4] = {0};

int main() {
	scanf("%d", &n);
	f[0] = 0;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		f[i] = f[i - 1] + a[i];
	}
	map<ll, int> mp;
	for (int i = 1; i <= n; ++i) {
		if (f[i] % 2 == 0) {
			dp[i][2] = mp[f[i] / 2];
		}
		mp[f[i]]++;
	}
	map<ll, ll> cnt;
	for (int i = 1; i <= n; ++i) {
		if (f[i] % 3 == 0) {
			dp[i][3] = cnt[f[i] / 3 * 2];
		}
		cnt[f[i]] += dp[i][2];
	}
	cout << dp[n][3];
	return 0;
}
