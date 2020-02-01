///created: 30/May/2019 14:31:15

#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	long long ans = 0;
	cin >> n;
	if (n == 1) { cout << 1; return 0; }
	ans = n;
	for (int i = n - 1; i >= 2; --i)
		ans = ans + 1LL * (i - 1) * (n - i) + i;
	cout << ans + 1;
	return 0;
}
