#include <bits/stdc++.h>

using namespace std;

int l[101], r[101], n, k;

inline bool inRange(int v, int l, int h) { return l <= v && v <= h; }

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d%d", &l[i], &r[i]);
	scanf("%d", &k);
	int res = 0;
	for (int i = n; i >= 1; --i)
		if (!inRange(k, l[i], r[i])) res++;
		else break;
	printf("%d\n", res + 1);	
	return 0;
}
