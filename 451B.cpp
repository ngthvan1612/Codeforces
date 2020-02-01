#include <bits/stdc++.h>

using namespace std;

int n, a[100001], t[100001];

void solve1() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	int s = 1, e;
	for (int i = 1; i < n && a[i] <= a[i + 1]; ++i)
		s = i + 1;
	e = s;
	for (int i = s; i < n && a[i] >= a[i + 1]; ++i)
		e = i + 1;
	int u = s, v = e;
//	fprintf(stderr, "s = %d, e = %d\n", s, e);
	while (u < v)
		swap(a[u++], a[v--]);
	for (int i = 1; i < n; ++i)
		if (a[i] > a[i + 1]) {
			printf("no");
			exit(0);
		}
	printf("yes\n%d %d", s, e);
}

void solve2() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	memcpy(t + 1, a + 1, sizeof (int) * n);
	sort(t + 1, t + 1 + n);
	int s = 1, e = 1;
	for (int i = 1; i <= n; ++i)
		if (a[i] != t[i]) e = i;
	for (int i = n; i >= 1; --i)
		if (a[i] != t[i]) s = i;
	int u = s, v = e;
	reverse(t + u, t + v + 1);
	if (memcmp(a + 1, t + 1, sizeof (int) * n) == 0)
		printf("yes\n%d %d", s, e);
	else printf("no");
}

int main() {
	solve2();
	return 0;
}

