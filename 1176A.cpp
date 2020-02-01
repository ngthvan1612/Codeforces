///created: 11/Jun/2019 13:49:33

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
	int q;
	ll n;
	for (cin >> q; q--;) {
		cin >> n;
		ll ans = 0;
		while (n % 2 == 0) {
			ans++;
			n /= 2;
		}
		while (n % 3 == 0) {
			n /= 3;
			ans += 2;
		}
		while (n % 5 == 0) {
			n /= 5;
			ans += 3;
		}
		cout << (n == 1 ? ans : -1) << '\n';
	}	
	return 0;
}
