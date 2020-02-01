#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, tmp, res = 1e9 + 7;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &tmp);
		res = min(res, tmp / max(n - i, i - 1));
	}
	printf("%d", res);
	return 0;
}
