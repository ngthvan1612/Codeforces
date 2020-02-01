///created: 7/Jun/2019 15:01:34

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
	ll n;
	int q;
	cin >> n >> q;
	while (q--) {
		ll u, v;
		cin >> u >> v;
		ll x = (u - 1) * n + v;
		if ((u + v) % 2 == 0) cout << (x + 1) / 2;
		else cout << (x + 1) / 2 + (n * n + 1) / 2;
		cout << '\n';
	}
	return 0;
}
