#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 3;
int x[N], n, q;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &x[i]);
	sort(x + 1, x + 1 + n);
	for (scanf("%d", &q); q--;) {
		int m;
		scanf("%d", &m);
		printf("%d\n", upper_bound(x + 1, x + 1 + n, m) - x - 1);
	}
	return 0;
}
