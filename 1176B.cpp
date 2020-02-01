///created: 11/Jun/2019 13:54:21

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
	int t, a[3] = {0}, n;
	for (cin >> t; t--;) {
		cin >> n;
		int ans = 0;
		memset(a, 0, sizeof a);
		for (int i = 1; i <= n; ++i) {
			int tmp;
			cin >> tmp;
			a[tmp % 3]++;
		}
		ans += a[0];
		int m = min(a[1], a[2]);
		ans += m;
		a[1] -= m;
		a[2] -= m;
		ans += a[1] / 3;
		ans += a[2] / 3;
		cout << ans << '\n';
	}
	return 0;
}
