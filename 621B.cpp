///created: 6/Jun/2019 15:01:19

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

int n;
map<int, int> mp1, mp2;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	while (n--) {
		int a, b;
		cin >> a >> b;
		mp1[a - b]++;
		mp2[a + b]++;
	}
	ll ans = 0;
	for (ii p : mp1)
		ans += 1LL * p.second * (p.second - 1) / 2;
	for (ii p : mp2)
		ans += 1LL * p.second * (p.second - 1) / 2;
	cout << ans;
	return 0;
}
