#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
int f[N][2];
char a[2][N];
int n, q;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> q;
	while (q--) {
		cin >> n;
		cin >> a[0] + 1 >> a[1] + 1;
		f[0][0] = 1;
		f[0][1] = 0;
		///repair
		for (int i = 1; i <= n; ++i)
			for (int j = 0; j < 2; ++j)
				if (a[j][i] < '3')
					a[j][i] = '0';
				else
					a[j][i] = '1';
		for (int i = 1; i <= n; ++i)
			for (int j = 0; j < 2; ++j) {
				if (a[j][i] == '0')
					f[i][j] = f[i - 1][j];
				else
					f[i][j] = (f[i - 1][j ^ 1] && (a[j ^ 1][i] == '1'));
			}
		if (f[n][1]) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
