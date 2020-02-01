#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, a[2][6] = {0};
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int tmp;
		cin >> tmp;
		a[0][tmp]++;
	}
	for (int i = 1; i <= n; ++i) {
		int tmp;
		cin >> tmp;
		a[1][tmp]++;
	}
	int ans = 0, ab = 0, ba = 0;
	for (int i = 1; i <= 5; ++i)
		if ((a[0][i] + a[1][i]) % 2 == 0) {
			int df = (a[0][i] + a[1][i]) / 2;
			ab += abs(df - a[0][i]);
			ba += abs(df - a[1][i]);
		}
		else {
			cout << -1;
			return 0;
		}
	if (ab != ba) cout << -1;
	else cout << ba / 2;	
	return 0;
}
