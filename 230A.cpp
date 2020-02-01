///created: 28/May/2019 14:46:44

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
ii a[1001];
int n, s;

int main() {
	scanf("%d%d", &s, &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d%d", &a[i].first, &a[i].second);
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; ++i) {
		if (s <= a[i].first) {
			printf("NO");
			return 0;
		}
		s += a[i].second;
	}
	printf("YES");
	return 0;
}
