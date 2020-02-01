#include <bits/stdc++.h>

using namespace std;

const int N = 5e2 + 5;
int a[N][N], n, m;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j)
			cin >> a[i][j];
	}
	for (int i = n - 1; i >= 1; --i)
		for (int j = m - 1; j >= 1; --j)
			if (a[i][j] == 0) {
				a[i][j] = min(a[i + 1][j], a[i][j + 1]) - 1;
				if (a[i][j] == 0) {
					cout << -1;
					return 0;
				}
			}
			else {
				if (a[i][j] >= a[i + 1][j] || a[i][j] >= a[i][j + 1]) {
					cout << -1;
					return 0;
				}
			}
	for (int i = 1; i <= n - 1; ++i)
		if (a[i][m] >= a[i + 1][m]) {
			cout << -1;
			return 0;
		}
	for (int j = 1; j <= m - 1; ++j)
		if (a[n][j] >= a[n][j + 1]) {
			cout << -1;
			return 0;
		}
	int sum = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			sum += a[i][j];
	cout << sum;
	return 0;
}
