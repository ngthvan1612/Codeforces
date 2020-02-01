#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, a[4 * 100000 + 1];
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		a[i + n] = a[i];
	}
	int res = 0;
	for (int i = 1; i <= 2 * n; ++i) {
		if (a[i] == 0) continue;
		int j = i, tmp = 0;
		while (j <= 2 * n && a[j] == 1) { j++; tmp++; }
		res = max(res, tmp);
		i = j;
	}
	printf("%d", res);
	return 0;
}
