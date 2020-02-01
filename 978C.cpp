#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 2 * 1e5 + 1;
ll a[N], dp[N];

int main() {
	int n, q;
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; ++i)
		scanf("%lld", &a[i]);
	dp[0] = 0;
	for (int i = 1; i <= n; ++i)
		dp[i] = dp[i - 1] + a[i];
	while (q--) {
		ll p;
		scanf("%lld", &p);
		int ll = 1, rr = n, res = 1;
		while (ll <= rr) {
			int mid = (ll + rr) / 2;
			if (dp[mid] >= p) { res = mid; rr = mid - 1; }
			else ll = mid + 1;
		}
		printf("%d %lld\n", res, 1LL * a[res] - dp[res] + p);
	}
	return 0;
}

