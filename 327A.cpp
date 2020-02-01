#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, a[101], res = 0, tmp = 0, f[102];
	cin >> n;
	f[0] = 0;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		f[i] = f[i - 1] + a[i];
	}
	for (int i = 1; i <= n; ++i)
		for (int j = i; j <= n; ++j)
			res = max(res, f[n] - f[j] + f[i - 1] - f[0] + (j - i + 1) - (f[j] - f[i - 1]));
	cout << res;
	return 0;
}
