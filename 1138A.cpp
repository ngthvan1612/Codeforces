#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 2;
int a[N], n, f[N], g[N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	int res = 0;
	vector<int> v;
	for (int i = 1; i <= n;) {
		int j = i + 1;
		while (j <= n && a[j] == a[i]) ++j;
		v.push_back(j - i);
		i = j;
	}
	for (int i = 0; i < int(v.size()) - 1; ++i)
		res = max(res, min(v[i], v[i + 1]) * 2);
	printf("%d\n", res);
	return 0;
}
