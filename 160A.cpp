///created: 28/May/2019 14:43:05

#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, t = 0, sum = 0, a[101];
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		sum += a[i];
	}
	int ans = 0;
	sort(a + 1, a + 1 + n);
	for (int i = n; i >= 1; --i) {
		t += a[i];
		sum -= a[i];
		if (t > sum) {
			ans = n - i + 1;
			break;
		}
	}
	cout << ans;
	return 0;
}
