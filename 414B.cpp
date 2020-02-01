///created: 9/Jun/2019 22:24:12

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

const int N = 2003;
const int mod = 1e9 + 7;
int f[N][N] = {0};
int n, k;
vector<int> g[N];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= i; ++j)
			if (i % j == 0)
				g[i].push_back(j);
	}
	for (int j = 1; j <= n; ++j)
		f[1][j] = 1;
	for (int i = 2; i <= k; ++i)
		for (int j = 1; j <= n; ++j) {
			for (int v : g[j]) {
				f[i][j] = (f[i][j] + f[i - 1][v]) % mod;
			}
		}
	int ans = 0;
	for (int i = 1; i <= n; ++i)
		ans = (ans + f[k][i]) % mod;
	cout << ans;
	return 0;
}
