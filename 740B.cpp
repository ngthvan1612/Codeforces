#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m, a[101], pre[101];
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	pre[0] = 0;
	for (int i = 1; i <= n; ++i)
		pre[i] = pre[i - 1] + a[i];
	int ans = 0;
	while (m--) {
		int l, r;
		cin >> l >> r;
		if (pre[r] - pre[l - 1] > 0)
			ans += pre[r] - pre[l - 1];
	}
	printf("%d\n", ans);
	return 0;
}
