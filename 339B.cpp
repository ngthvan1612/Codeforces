///created: 30/May/2019 09:41:30

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m, cur = 1;
	cin >> n >> m;
	ll ans = 0;
	while (m--) {
		int a;
		cin >> a;
		ans += (a - cur + n) % n;
		cur = a;
	}
	cout << ans;
	return 0;
}
