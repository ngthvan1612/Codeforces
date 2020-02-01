#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, a[201], m, ans = 0;
	cin >> n >> m;
	while (n--) {
		for (int i = 1; i <= 2 * m; ++i)
			cin >> a[i];
		for (int i = 1; i <= m; ++i)
			ans += (a[i * 2 - 1] || a[i * 2]);	
	}
	cout << ans;
	return 0;
}
