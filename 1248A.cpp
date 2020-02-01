#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int t, n, m;
	for (cin >> t; t--;) {
		cin >> n;
		int cn = 0, ln = 0, cm = 0, lm = 0;
		for (int i = 1; i <= n; ++i) {
			int p;
			cin >> p;
			if (p % 2) ln++;
			else cn++;
		}
		cin >> m;
		for (int i = 1; i <= m; ++i) {
			int q;
			cin >> q;
			if (q % 2) lm++;
			else cm++;
		}
		cout << 1LL * cn * cm + 1LL * lm * ln << '\n';
	}
	return 0;
}
