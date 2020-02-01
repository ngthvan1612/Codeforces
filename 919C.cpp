///created: 7/Jun/2019 15:52:25

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

int n, m, k, f[2001];
char a[2003][2003];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; ++i)
		scanf("%s", a[i] + 1);
	f[0] = 0;
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (a[i][j] == '.')
				f[j] = f[j - 1] + 1;
			else f[j] = 0;
			ans += f[j] >= k;
		}
	}
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (a[j][i] == '.')
				f[j] = f[j - 1] + 1;
			else f[j] = 0;
			ans += f[j] >= k;
		}
	}
	if (k == 1) ans /= 2;
	cout << ans;
	return 0;
}
