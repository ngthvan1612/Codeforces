#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 3;
int a[N], n;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	int rev = 1, i = 1, j = n;
	while (i < j) {
		if (rev) swap(a[i], a[j]);
		rev ^= 1;
		i++;
		j--;
	}
	for (int i = 1; i <= n; ++i)
		printf("%d ", a[i]);
	return 0;
}
