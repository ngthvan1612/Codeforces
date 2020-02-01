///created: 10/Jun/2019 18:07:07

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
	ll r, g, b;
	cin >> r >> g >> b;
	if (r > 2 * (g + b)) cout << g + b;
	else if (g > 2 * (r + b)) cout << r + b;
	else if (b > 2 * (r + g)) cout << r + g;
	else cout << (r + g + b) / 3;
	return 0;
}
