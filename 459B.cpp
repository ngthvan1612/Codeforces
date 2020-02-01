#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 1;
int a[N], n;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	sort(a + 1, a + 1 + n);
	cout << a[n] - a[1] << ' ';
	int i = 2, j = n - 1;
	while (i <= n && a[i] == a[1]) ++i;
	--i;
	while (j >= 1 && a[j] == a[n]) --j;
	++j; j = (n - j + 1);
	if (i < n) cout << 1LL * i * j;
	else cout << 1LL * 1LL * n * (n - 1) / 2;
	return 0;
}
