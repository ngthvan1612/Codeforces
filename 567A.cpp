///created: 28/May/2019 14:55:47

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
ii a[100001], ans[100001], p[100001];
int n;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i].first);
		a[i].second = i;
	}
	sort(a + 1, a + 1 + n);
	ans[1].first = a[2].first - a[1].first;
	ans[n].first = a[n].first - a[n - 1].first;
	for (int i = 2; i <= n - 1; ++i)
		ans[i].first = min(a[i].first - a[i - 1].first, a[i + 1].first - a[i].first);
	ans[1].second = a[n].first - a[1].first;
	ans[n].second = ans[1].second;
	for (int i = 2; i <= n - 1; ++i)
		ans[i].second = max(a[i].first - a[1].first, a[n].first - a[i].first);
	for (int i = 1; i <= n; ++i)
		p[a[i].second] = ans[i];
	for (int i = 1; i <= n; ++i)
		printf("%d %d\n", p[i].first, p[i].second);
	return 0;
}
