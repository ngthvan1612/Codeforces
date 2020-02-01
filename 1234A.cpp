#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int q, n;
	cin >> q;
	while (q--) {
		cin >> n;
		int a;
		ll sum = 0;
		for (int i = 1; i <= n; ++i) {
			cin >> a;
			sum += 1LL * a;
		}
		ll w = sum / n;
		while (w * n < sum)
			++w;
		cout << w << '\n';
	}
	return 0;
