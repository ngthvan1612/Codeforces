#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, res = 0;
	cin >> n;
	int d = int(sqrt(n));
	int r = n / d;
	if (r * d == n) res = r + d;
	else res = r + d + 1;
	cout << res;
	return 0;
}
