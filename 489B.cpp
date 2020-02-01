///created: 2/Jun/2019 21:26:28

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int n, m, a[101], b[101], f[101][101] = {0};

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	cin >> m;
	for (int j = 1; j <= m; ++j)
		cin >> b[j];
	sort(a + 1, a + 1 + n);
	sort(b + 1, b + 1 + m);
	int ans = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (abs(a[i] - b[j]) <= 1) {
				b[j] = 1e9;
				ans++;
				break;
			}
	cout << ans;
	return 0;
}
