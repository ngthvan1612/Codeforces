#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, a[2001], d;
	cin >> n >> d;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	int ans = 0;
	for (int i = 2; i <= n; ++i)
		if (a[i - 1] >= a[i]) {
			int tmp = max((a[i - 1] - a[i]) / d, 1);
			while (a[i - 1] >= a[i] + tmp * d) ++tmp;
			a[i] += tmp * d;
			ans += tmp;
		}
	cout << ans;
	return 0;
}
