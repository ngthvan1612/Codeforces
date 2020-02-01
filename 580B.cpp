///created: 9/Jun/2019 18:22:49

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

int n, d;
ii a[100005];
ll f[100005];

bool cmp(ii a, ii b) {
	return a.first < b.first;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> d;
	for (int i = 1; i <= n; ++i)
		cin >> a[i].first >> a[i].second;
	sort(a + 1, a + 1 + n);
	f[0] = 0LL;
	for (int i = 1; i <= n; ++i)
		f[i] = f[i - 1] + a[i].second;
	int i = 1, j = 1;
	ll ans = 0;
	while (i <= n) {
		while (a[j].first <= a[i].first - d)
			++j;
		ans = max(ans, f[i] - f[j - 1]);
		++i;
	}
	cout << ans;
	return 0;
}
