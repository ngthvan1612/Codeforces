///created: 6/Jun/2019 11:42:35

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
	ll a, b, c;
	cin >> a >> b >> c;
	ll m = max(a, max(b, c));
	if (m == c) cout << max(c - a - 1, 0LL) + max(c - b - 1, 0LL);
	else if (m == b) cout << max(b - c - 1, 0LL) + max(b - a - 1, 0LL);
	else cout << max(a - b - 1, 0LL) + max(a - c - 1, 0LL);
	return 0;
}
