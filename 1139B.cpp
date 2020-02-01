#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, a[2 * 100000 + 1], m;
	long long res = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	m = 1e9 + 7;
	for (int i = n; i >= 1; --i)
		a[i - 1] = min(a[i - 1], a[i] - 1);
	for (int i = n; i >= 1; --i)
		if (a[i] > 0)
			res = res + a[i];
		else break;
	cout << res;
	return 0;
}

