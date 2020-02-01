///created: 7/Jun/2019 21:48:12

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
	ll n, m, p;
	cin >> n >> m;
	if (m == 0) {
		cout << n << ' ' << n << '\n';
		return 0;
	}
	p = 0;
	while (p * (p - 1) / 2 < m) ++p;
	cout << max(0LL, n - 2 * m) << ' ' << n - p;
	return 0;
}
