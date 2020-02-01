#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, a[11] = {0}, ans = 0, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		int tmp;
		scanf("%d", &tmp);
		ans = ans + i - 1 - a[tmp];
		a[tmp]++;
	}
	printf("%d", ans);
	return 0;
}
