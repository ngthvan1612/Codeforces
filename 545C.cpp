///created: 9/Jun/2019 17:46:21

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

const int N = 1e5 + 2;
int x[N], h[N], dp[N][3], n;
///0:stay, 1: left, 2:right

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> x[i] >> h[i];
	x[n + 1] = x[n] + h[n] + 1;
	h[n + 1] = 0;
	dp[1][0] = 0;
	dp[1][1] = 1;
	dp[1][2] = (x[1] + h[1] < x[2]);
	for (int i = 2; i <= n; ++i) {
		///stay
		for (int j = 0; j < 3; ++j)
			dp[i][j] = dp[i - 1][j];
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
		if (x[i] > x[i - 1] + h[i - 1]) dp[i][0] = max(dp[i][0], dp[i - 1][2]);
		///left
		if (x[i] - h[i] > x[i - 1])
			dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) + 1;
		if (x[i] - h[i] > x[i - 1] + h[i - 1])
			dp[i][1] = max(dp[i][1], dp[i - 1][2] + 1);
		///right
		if (x[i] + h[i] < x[i + 1]) {
			dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + 1;
			if (x[i - 1] + h[i - 1] < x[i])
				dp[i][2] = max(dp[i][2], dp[i - 1][2] + 1);
		}
	}
	cout << max(dp[n][0], max(dp[n][1], dp[n][2]));
	return 0;
}
