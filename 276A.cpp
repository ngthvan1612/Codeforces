///created: 30/May/2019 16:41:06

#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, k, ans = -2e9 - 7;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i) {
		int f, t;
		scanf("%d%d", &f, &t);
		if (t > k) ans = max(ans, f - t + k);
		else ans = max(ans, f);
	}
	cout << ans;
	return 0;
}
