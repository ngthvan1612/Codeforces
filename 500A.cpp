///created: 30/May/2019 18:21:48

#include <bits/stdc++.h>

using namespace std;

const int N = 3e4 + 1;
int n, a[N], vs[N] = {0}, t;

int main() {
	scanf("%d%d", &n, &t);
	for (int i = 1; i <= n - 1; ++i)
		scanf("%d", &a[i]);
	for (int i = 1; !vs[i]; i = i + a[i])
		vs[i] = 1;
	printf(vs[t] ? "YES" : "NO");
	return 0;
}
