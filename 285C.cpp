///created: 31/May/2019 20:06:27

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int N = 3e5 + 1;
int a[N], n;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	sort(a + 1, a + 1 + n);
	ll ans = 0;
	for (int i = 1; i <= n; ++i)
		ans += abs(i - a[i]);
	cout << ans;
	return 0;
}
