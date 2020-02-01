///created: 31/May/2019 15:58:19

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main() {
	int n, a[3001], ans = 0, p = 1, vs[6001] = {0};
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; ++i)
		if (vs[a[i]]) {
			for (int j = a[i] + 1; ; ++j)
				if (!vs[j]) {
					vs[j] = 1;
					ans += j - a[i];
					break;
				}
		}
		else vs[a[i]] = 1;
	cout << ans;
	return 0;
}
