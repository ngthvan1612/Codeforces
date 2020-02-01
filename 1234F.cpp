#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 7;
const int M = (1 << 20);
char a[N];
int dp[M + 1];

int main() {
	scanf("%s", a + 1);
	int n = int(strlen(a + 1));
	memset(dp, 0, sizeof dp);
	for (int i = 1; i <= n; ++i) {
		int state = 0;
		for (int j = 1; j <= 20 && i - j + 1 >= 1; ++j)
			if (state & (1 << (a[i - j + 1] - 'a'))) break;
			else {
				state |= (1 << (a[i - j + 1] - 'a'));
				dp[state] = j;
			}
	}
	for (int s = 1; s < M; ++s)
		for (int j = 0; j < 20; ++j)
			if (s & (1 << j))
				dp[s] = max(dp[s], dp[s ^ (1 << j)]);
	int res = 0;
	for (int s = 0; s < M; ++s) {
		int rev = (M - 1) ^ s;
		res = max(res, dp[s] + dp[rev]);
	}
	cout << res;
	return 0;
}
