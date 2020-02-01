///created: 27:04:2019 19:32:47

#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 1;
int f[N], n, ans[N];

int main() {
	cin >> n;
	int i = 1, j = n, cnt = 0;
	while (i <= j) {
		f[i] = ++cnt;
		if (i < j)
			f[j] = ++cnt;
		++i;
		--j;
	}
	for (int i = 1; i <= n; ++i)
		ans[f[i]] = i;
	for (int i = 1; i <= n; ++i)
		printf("%d ", ans[i]);
	return 0;
}
