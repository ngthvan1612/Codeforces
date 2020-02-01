///created: 30/May/2019 18:28:48

#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 1;
int a[N], dp[N][2], n;

int main() {
	scanf("%d", &n);
	dp[0][0] = dp[0][1] = 0;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		dp[i][0] = dp[i - 1][0];
		dp[i][1] = dp[i - 1][1];
		dp[i][i % 2] += a[i];
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i)
		if (dp[i - 1][0] + dp[n][1] - dp[i][1] == dp[i - 1][1] + dp[n][0] - dp[i][0])
			ans++;
	printf("%d\n", ans);
	return 0;
}
