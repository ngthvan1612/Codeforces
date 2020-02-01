///created: 30/May/2019 16:31:27

#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, a[2001], rk[2001] = {0}, rank = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		rk[a[i]]++;
	}
	for (int i = 2000; i >= 1; --i)
		if (rk[i]) {
			int tmp = rk[i];
			rk[i] = rank + 1;
			rank += tmp;
		}
	for (int i = 1; i <= n; ++i)
		printf("%d ", rk[a[i]]);	
	return 0;
}
