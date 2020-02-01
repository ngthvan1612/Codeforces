///created: 28/May/2019 15:34:19

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, a[300001];
ll pow2(int a) { return 1LL * a * a; }

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	sort(a + 1, a + 1 + n);
	ll ans = 0;
	int i = 1, j = n;
	while (i < j) {
		ans += pow2(a[i] + a[j]);
		++i;
		--j;
	}
	cout << ans;	
	return 0;
}
