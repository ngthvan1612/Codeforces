///created: 31/May/2019 07:57:19

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 1;
const int M = 1e6 + 1;
int n, a[N], f[N], m, E = 0;

int main() {
	scanf("%d", &n);
	f[0] = 0;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		f[i] = f[i - 1] + a[i];
	}
	for (scanf("%d", &m); m--;) {
		int q;
		scanf("%d", &q);
		printf("%d\n", upper_bound(f + 1, f + 1 + n, q - 1) - f);
	}
	return 0;
}
