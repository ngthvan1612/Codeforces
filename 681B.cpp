///created: 7/Jun/2019 13:59:59

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
	cin >> n;
	for (ll a = 0; a * 1234567 <= n; ++a)
		for (ll b = 0; b * 123456 + a * 1234567 <= n; ++b)
			if ((n - a * 1234567 - b * 123456) % 1234 == 0) {
				cout << "YES";
				return 0;
			}
	cout << "NO";
	return 0;
}
