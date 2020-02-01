///created: 1/Jun/2019 09:39:25

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main() {
	int n, a[101], m = 0, ans = 0;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		m = max(m, a[i]);
	}
	for (int i = 1; i <= n; ++i)
		ans += m - a[i];
	cout << ans;
	return 0;
}
