#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, res1 = 0, res2 = 0;
	cin >> n;
	if (n % 7 == 0) cout << n / 7 * 2 << ' ' << n / 7 * 2;
	else if (n % 7 == 1) cout << n / 7 * 2 << ' ' << 1 + n / 7 * 2;
	else if (n % 7 <= 5) cout << n / 7 * 2 << ' ' << 2 + n / 7 * 2;
	else cout << n / 7 * 2 + 1 << ' ' << n / 7 * 2 + 2;
	return 0;
}
