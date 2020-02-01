#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, k, ans = 0, t;
	cin >> n >> k;
	t = 2 * int(sqrt(1.0 * (240 - k))) / 5;
	while (1LL * t * (t + 1) / 2 * 5 <= 1LL * (240 - k)) ans = t++;
	cout << min(ans, n);
	return 0;

