///created: 12/Jun/2019 11:00:06

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

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, l, r, x, c[16];
	cin >> n >> l >> r >> x;
	for (int i = 0; i < n; ++i)
		cin >> c[i];
	int ans = 0;
	for (int s = 1; s < (1 << n); ++s) {
		int cmin = 1e9 + 7, cmax = - 1e9 - 7, sum = 0;
		for (int j = 0; j < n; ++j)
			if (s & (1 << j)) {
				cmin = min(cmin, c[j]);
				cmax = max(cmax, c[j]);
				sum += c[j];
			}
		if (cmax - cmin >= x && sum >= l && sum <= r)
			ans++;
	}
	cout << ans;
	return 0;
}
