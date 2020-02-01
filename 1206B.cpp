#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
typedef long long ll;
int a[N], n;
ll f[N][2];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i)
			cin >> a[i];
	f[0][0] = 0;
	f[0][1] = 1e18 + 7;
	for (int i = 1; i <= n; ++i) {
		f[i][0] = min(f[i - 1][0] + abs(a[i] - 1), f[i - 1][1] + abs(a[i] + 1));
		f[i][1] = min(f[i - 1][1] + abs(a[i] - 1), f[i - 1][0] + abs(a[i] + 1));
		//printf("[%d]: [%d, %d]\n", i, f[i][0], f[i][1]);
	}
	cout << f[n][0];
	return 0;
}
