#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;
int color[N], n, k, prime[N], c[N], top;

int main() {
	prime[0] = prime[1] = 0;
	cin >> n;
	n++;
	for (int i = 2; i <= n; ++i)
		prime[i] = 1;
	k = 1;
	for (int i = 2; i <= n; ++i)
		if (prime[i]) {
			color[i] = 1;
			for (long long j = 1LL * i * i; j <= 1LL * n; j += i) {
				color[j] = max(color[j], color[i] + 1);
				prime[j] = 0;
				k = max(k, color[j]);
			}
		}
	printf("%d\n", k);
	for (int i = 2; i <= n; ++i)
		printf("%d ", color[i]);
	return 0;
}
