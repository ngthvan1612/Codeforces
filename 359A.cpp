#include <bits/stdc++.h>

using namespace std;

int main() {
	int m, n, res = 4;
	cin >> m >> n;
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			int a;
			cin >> a;
			if (a) {
				if (i == 1 || j == 1 || i == m || j == n) res = min(res, 2);
				if (i == 1 && j == 1) res = min(res, 1);
				if (i == 1 && j == n) res = min(res, 1);
				if (i == m && j == 1) res = min(res, 1);
				if (i == m && j == n) res = min(res, 1);
			}
		}
	}
	cout << res;
	return 0;
}
