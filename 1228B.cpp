#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
const int N = 1e3 + 5;
int a[N][N];
int h, w, c[N], r[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> h >> w;
	for (int i = 1; i <= h; ++i)
		cin >> r[i];
	for (int j = 1; j <= w; ++j)
		cin >> c[j];
	memset(a, 0, sizeof a);
	for (int i = 1; i <= h; ++i) {
		for (int v = 1; v <= r[i]; ++v)
			a[i][v] = 1;
		a[i][r[i] + 1] = -1;
	}
	for (int j = 1; j <= w; ++j) {
		for (int v = 1; v <= c[j]; ++v) {
			if (a[v][j] == -1) {
				cout << 0;
				return 0;
			}
			a[v][j] = 1;
		}
		if (a[c[j] + 1][j] == 1) {
			cout << 0;
			return 0;
		}
		a[c[j] + 1][j] = -1;
	}
	int ans = 1;
	for (int i = 1; i <= h; ++i)
		for (int j = 1; j <= w; ++j)
			if (a[i][j] == -1 || a[i][j] == 1)
				ans *= 1;
			else {
				ans = int((1LL * ans * 2) % (1LL * mod));
			}
	cout << ans;
	return 0;
}
