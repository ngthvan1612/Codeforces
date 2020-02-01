#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, a[100001], res = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n;) {
		int j = i + 1;
		while (j <= n && a[j] == a[j - 1]) ++j;
		res++;
		i = j;
	}
	cout << res;
	return 0;
}

