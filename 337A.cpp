#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m, a[51], res = 1e9 + 7;
	cin >> n >> m;
	for (int i = 1; i <= m; ++i)
		cin >> a[i];
	sort(a + 1, a + 1 + m);
	for (int i = n; i <= m; ++i)
		res = min(res, a[i] - a[i - n + 1]);
	cout << res;
	return 0;
}

