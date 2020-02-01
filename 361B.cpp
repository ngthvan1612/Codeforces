#include <bits/stdc++.h>

using namespace std;

int a[100001];

int main() {
	int n, k;
	cin >> n >> k;
	if (n == 1 && k == 0) {
		cout << 1;
		return 0;
	}
	if (n == 1 || n == k) {
		cout << -1;
		return 0;
	}
	for (int i = 1; i <= n; ++i)
		a[i] = i;
	for (int i = k + 2; i <= n; i += 2) {
		if (i + 1 <= n)
			swap(a[i], a[i + 1]);
	}
	if (a[n] == n && k != n - 1) swap(a[1], a[n]);
	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		cnt += (__gcd(a[i], i) > 1);
		printf("%d ", a[i]);
	}
	printf("\n");
	fprintf(stderr, "debug: cnt = %d\n", cnt);
	return 0;
