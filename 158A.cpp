#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, k, a[51];
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	int res = 0;
	for (int i = 1; i <= n; ++i)
		if (a[i] >= a[k] && a[i])
			res++;
	cout << res;
	return 0;
}
