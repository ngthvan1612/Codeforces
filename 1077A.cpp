///created: 1/Jun/2019 09:57:58

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int t;
	ll a, b, k;
	for (cin >> t; t--;) {
		cin >> a >> b >> k;
		ll ans = a * (k - k / 2) - b * (k / 2);
		cout << ans << '\n';
	}
	return 0;
}
