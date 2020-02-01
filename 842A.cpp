///created: 7/Jun/2019 13:15:53

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
	int l, r, x, y, k;
	cin >> l >> r >> x >> y >> k;
	for (int i = l; i <= r; ++i)
		if (i % k == 0 && x <= i / k && i / k <= y) {
			cout << "YES";
			return 0;
		}
	cout << "NO";
	return 0;
}
