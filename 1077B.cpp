///created: 28/May/2019 15:23:42

#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, a[101], ans = 0;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 2; i <= n - 1; ++i)
		if (a[i] == 0) {
			if (a[i - 1] == 0 || a[i + 1] == 0) continue;
			a[i + 1] = 0;
			ans++;
		}
	cout << ans;
	return 0;
}
