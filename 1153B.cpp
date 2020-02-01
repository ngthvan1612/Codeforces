#include <bits/stdc++.h>

using namespace std;

int main() {
	int m, n, h, a[101], b[101], c[101][101];
	cin >> n >> m >> h;
	for (int i = 1; i <= m; ++i) cin >> a[i];
	for (int i = 1; i <= n; ++i) cin >> b[i];
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cin >> c[i][j];
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (c[i][j])
				c[i][j] = min(a[j], b[i]);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j)
			cout << c[i][j] << ' ';
		cout << '\n';
	}
	return 0;
}

