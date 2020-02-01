///created: 21/Jun/2019 17:35:02

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

int n, k, a[501], b[501], ans = 0;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i < n; ++i) {
		if (a[i] + a[i + 1] < k) {
			int diff = k - (a[i] + a[i + 1]);
			ans += diff;
			a[i + 1] += diff;
			b[i + 1] = diff;
		}
	}
	cout << ans << '\n';
	for (int i = 1; i <= n; ++i)
		cout << a[i] << ' ';
	return 0;
}
