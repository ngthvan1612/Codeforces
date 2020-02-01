#include <bits/stdc++.h>

using namespace std;

int n, l;
double a[1005];

int main() {
	cin >> n >> l;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	sort(a + 1, a + 1 + n);
	double res = 0.00;
	if (a[1] != 0.0) res = max(res, a[1]);
	if (a[n] != l) res = max(res, (l - a[n]));
	for (int i = 1; i <= n - 1; ++i)
		res = max(res, (a[i + 1] - a[i]) / 2.0);
	cout << fixed << setprecision(15) << res;
	return 0;
}
