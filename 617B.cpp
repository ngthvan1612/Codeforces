///created: 3/Jun/2019 21:29:44

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
#define db(x) cerr << "debug: " << #x << " = " << x << '\n';

int main() {
	///ios::sync_with_stdio(0); cin.tie(0);
	int n, a[106], has1 = false;;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		has1 |= (a[i] == 1);
	}
	ll ans = 1;
	for (int i = 1, j = -1; i <= n; ++i)
		if (a[i] == 1) {
			if (j != -1) ans *= i - j;
			j = i;
		}
	cout << ans * has1;
	return 0;
}
