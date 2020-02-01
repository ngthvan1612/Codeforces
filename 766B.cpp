#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 3;
int a[N], n;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n - 2; ++i)
		if (a[i] + a[i + 1] > a[i + 2] && a[i + 1] + a[i + 2] > a[i] && a[i] + a[i + 2] > a[i + 1]) {
			cout << "YES";
			return 0;
		}
	cout << "NO";
	return 0;
}
