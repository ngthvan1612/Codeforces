///created: 21/Jun/2019 21:18:00

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

const int modulo = 1e9 + 7;
int t, k, f[100005][2] = {0}, dp[100005];
#define W 1
#define R 0

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> t >> k;
	f[0][R] = 1;
	dp[0] = 0;
	for (int i = 1; i <= int(1e5); ++i) {
		f[i][R] = (f[i - 1][R] + f[i - 1][W]) % modulo;
		if (i - k >= 0)
			f[i][W] = (f[i - k][W] + f[i - k][R]) % modulo;
		dp[i] = (dp[i - 1] + f[i][R]) % modulo;
		dp[i] = (dp[i] + f[i][W]) % modulo;
	}
	while (t--) {
		int a, b, l = 0, r = 0;
		cin >> a >> b;
		cout << ((dp[b] - dp[a - 1]) % modulo + modulo) % modulo << '\n';
	}
	return 0;
}
