///created: 31/May/2019 15:29:55

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main() {
	int n, m, tmp, ans = 0, sn, sm;
	cin >> n >> m;
	for (int i = 0; i <= n + m; i++) {
		sn = n, sm = m;
		n -= i, m -= 2 * i;
		if (n < 0 || m < 0) break;
		ans = max(ans, i + min(n / 2, m));
		n = sn, m = sm;
	}
	cout << ans;
	return 0;
}
