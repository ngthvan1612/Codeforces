#include <bits/stdc++.h>

using namespace std;

int main() {
	const int N = 2e5 + 1;
	int n, q[N], p[N], check[N], m = 0;
	memset(check, 0, sizeof check);
	scanf("%d", &n);
	for (int i = 1; i <= n - 1; ++i) {
		scanf("%d", &q[i]);
	}
	p[n] = 0;
	for (int i = n - 1; i >= 1; --i) {
		p[i] = p[i + 1] - q[i];
		if (m > p[i]) m = p[i];
	}
	m = -m + 1;
	for (int i = 1; i <= n; ++i) {
		p[i] = p[i] + m;
		if (p[i] < N && p[i] > 0)
			check[p[i]] = 1;
	}
	for (int i = 1; i <= n; ++i)
		if (check[i] == 0) { printf("-1"); return 0; }
	for (int i = 1; i <= n; ++i)
		printf("%d ", p[i]);
	return 0;
}
