///created: 27:04:2019 19:19:27

#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 3;
int a[N], n, ans[N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		ans[i] = 1e9 + 7;
	}
	for (int i = 1, j = - 1e9 - 7; i <= n; ++i) {
		if (a[i] == 0) j = i;
		ans[i] = min(ans[i], i - j);
	}
	for (int i = n, j = 1e9 + 7; i >= 1; --i) {
		if (a[i] == 0) j = i;
		ans[i] = min(ans[i], j - i);
	}
	for (int i = 1; i <= n; ++i)
		printf("%d ", ans[i]);
	return 0;
}
