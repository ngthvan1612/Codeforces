///created: 6/Jun/2019 14:31:40

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
ll a[200001], s;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> s;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	sort(a + 1, a + 1 + n);
	ll ans = 0;
	for (int i = n / 2 + 1; i <= n; ++i)
		if (a[i] < s)
			ans += s - a[i];
	for (int i = 1; i <= n / 2 + 1; ++i)
		if (a[i] > s)
			ans += a[i] - s;
	cout << ans;
	return 0;
}
