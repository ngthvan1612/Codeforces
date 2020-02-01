#include <bits/stdc++.h>

using namespace std;

int main() {
	int k, n, m, a[1002];
	cin >> n >> m >> k;
	for (int i = 1; i <= m + 1; ++i)
		cin >> a[i];
	int ans = 0;
	for (int i = 1; i <= m; ++i)
		if (__builtin_popcount(a[i] ^ a[m + 1]) <= k)
			ans++;
	cout << ans;	
	return 0;
}
