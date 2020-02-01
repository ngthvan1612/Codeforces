///created: 28/May/2019 14:51:26

#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, a, p, ans = 0, pmin = 1e9 + 7;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d", &a, &p);
		pmin = min(pmin, p);
		ans += a * pmin;
	}
	printf("%d", ans);
	return 0;
}
