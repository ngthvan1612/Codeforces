///created: 5/Jun/2019 19:16:17

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
#define db(x) cerr << "debug: " << #x << " = " << x << '\n';

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m, a[101], b[101];
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= m; ++i)
		cin >> b[i];
	sort(a + 1, a + 1 + n);
	sort(b + 1, b + 1 + m);
	for (int i = 1; i <= 100; ++i)
		if (a[n] <= i && b[1] > i && 2 * a[1] <= i) {
			cout << i;
			return 0;
		}
	cout << -1;
	return 0;
}
