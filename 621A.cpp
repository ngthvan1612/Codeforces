///created: 30/May/2019 15:58:17

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int n, m = 1e9 + 7;
ll ans = 0;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		int a;
		scanf("%d", &a);
		if (a % 2 == 1) m = min(m, a);
		ans += a;
	}
	if (ans % 2 == 1) ans -= m;
	cout << ans;
	return 0;
}
