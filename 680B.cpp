#include <bits/stdc++.h>

using namespace std;

int n, k, a[100001];

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	int res = 0;
	for (int i = 0; k - i >= 1 || i + k <= n; ++i) {
		if (k - i >= 1 && i + k <= n && a[i + k] && a[k - i]) res += (i == 0 ? 1 : 2);
		if (k - i < 1 && i + k <= n && a[i + k]) res += 1;
		if (k - i >= 1 && i + k > n && a[k - i]) res += 1;
	}		
	printf("%d", res);
	return 0;
}
