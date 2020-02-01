#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	int n, dp[8002] = {0}, a, b, c;
	cin >> n >> a >> b >> c;
	dp[0] = 0;
	for (int i = 0; i <= n; ++i) {
		if (i != 0 && dp[i] == 0) continue;		
		dp[i + a] = max(dp[i + a], dp[i] + 1);
		dp[i + b] = max(dp[i + b], dp[i] + 1);
		dp[i + c] = max(dp[i + c], dp[i] + 1);
	}
	cout << dp[n];
	return 0;
}
