///created: 4/Jun/2019 20:58:17

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
#define db(x) cerr << "debug: " << #x << " = " << x << '\n';

const int N = 2e5 + 2;
int a[N], n;
ll p[N], s[N];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	p[0] = s[n + 1] = 0;
	for (int i = 1; i <= n; ++i)
		p[i] = p[i - 1] + a[i];
	for (int i = n; i >= 1; --i)
		s[i] = s[i + 1] + a[i];
	ll ans = 0;
	int i = 1, j = n;
	while (i < j) {
		while (p[i] < s[j]) ++i;
		if (p[i] == s[j] && i != j) ans = max(ans, p[i]);
		--j;
	}
	cout << ans;
	return 0;
}
