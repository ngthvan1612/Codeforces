#include <bits/stdc++.h>

using namespace std;

int n, a[100001];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	sort(a + 1, a + 1 + n);
	int i = 1, j = n;
	while (i <= n && a[i] == a[1]) ++i;
	while (j >= 1 && a[j] == a[n]) --j;
	cout << max(0, j - i + 1);
	return 0;
}
