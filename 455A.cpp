#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	int n, f[100001] = {0};
	ll dp[100001] = {0};
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		int tmp;
		scanf("%d", &tmp);
		f[tmp]++;
	}
	dp[0] = 0;
	dp[1] = 1LL * f[1];
	dp[2] = max(dp[1], 2LL * f[2]);
	for (int i = 3; i <= 100000; ++i)
		dp[i] = max(1LL * dp[i - 1], 1LL * dp[i - 2] + 1LL * i * f[i]);
	printf("%lld", dp[100000]);
	return 0;
}

