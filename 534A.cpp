#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, a[5003];
	cin >> n;
	if (n <= 2) { cout << 1 << '\n' << 1; return 0; }
	if (n == 3) { cout << 2 << '\n' << 1 << ' ' << 3; return 0; }
	int i = 1, j = n, rev = 1;
	for (int i = 1; i <= n; ++i)
		a[i] = i;
	while (i < j) {
		if (rev) swap(a[i], a[j]);
		++i;
		--j;
		rev ^= 1;
	}
	swap(a[1], a[n / 2]);
	swap(a[n], a[n / 2 + 1]);
	printf("%d\n", n);
	for (int i = 1; i <= n; ++i)
		if (i % 2 == 0) cout << i << ' ';
	for (int i = 1; i <= n; ++i)
		if (i % 2 != 0) cout << i << ' ';
	return 0;
}
