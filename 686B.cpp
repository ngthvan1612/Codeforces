#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, a[101];
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= n; ++i)
		for (int j = n - 1; j >= 1; --j)
			if (a[j] > a[j + 1]) {
				swap(a[j], a[j + 1]);
				printf("%d %d\n", j, j + 1);
			}
	return 0;
}
