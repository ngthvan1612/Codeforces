///created: 1/Jun/2019 14:04:57

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main() {
	int k2, k3, k5, k6;
	int ans = 0;
	cin >> k2 >> k3 >> k5 >> k6;
	for (int i = 0; i <= k3; ++i) {
		int res = i * 32;
		int c2 = k2 - i;
		if (c2 < 0) break;
		res += min(c2, min(k5, k6)) * 256;
		ans = max(ans, res);
	}
	cout << ans;
	return 0;
}
