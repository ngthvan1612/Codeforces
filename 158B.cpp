#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, a[5] = {0}, res = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		int tmp; scanf("%d", &tmp);
		a[tmp]++;
	}
	while (a[3] && a[1]) { a[3]--; a[1]--; res++; }
	while (a[2] >= 2) { a[2] -= 2; res++; }
	while (a[1] >= 2 && a[2]) { a[1] -= 2; a[2]--; res++; }
	while (a[1] >= 4) { a[1] -= 4; res++; }
	if (a[3]) res += a[3];
	if (a[2]) res++, a[1]--;
	if (a[1] > 0) res++;
	res += a[4];
	printf("%d", res);
	return 0;
}

