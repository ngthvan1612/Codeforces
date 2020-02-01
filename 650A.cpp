///created: 10/Jun/2019 21:16:33

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
	int n;
	cin >> n;
	map<int, int> mpx, mpy;
	map<ii, int> mp;
	for (int i = 1; i <= n; ++i) {
		int x, y;
		cin >> x >> y;
		mpx[x]++;
		mpy[y]++;
		mp[ii(x, y)]++;
	}
	ll ans = 0;
	for (ii p : mpx)
		ans += 1LL * p.second * (p.second - 1) / 2;
	for (ii p : mpy)
		ans += 1LL * p.second * (p.second - 1) / 2;
	for (pair<ii, int> p : mp)
		ans -= 1LL * p.second * (p.second - 1) / 2;
	cout << ans;	
	return 0;
}
