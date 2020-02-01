#include <bits/stdc++.h>

using namespace std;

int n, m, k;

int main() {
	cin >> n >> m;
	if (m % n != 0) { cout << -1; return 0; }
	k = m / n;
	int res = 0;
	while (k > 1) {
		if (k % 2 == 0) { k /= 2; res++; }
		else if (k % 3 == 0) { k /= 3; res++; }
		else { cout << -1; return 0; }
	}
	cout << res;
	return 0;
}
