#include <bits/stdc++.h>

using namespace std;

int main() {
	int a[101], n, k, b[101];
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= k; ++i)
		cin >> b[i];
	sort(b + 1, b + 1 + k, greater<int>());
	int ind = 1;
	for (int i = 1; i <= n; ++i)
		if (a[i] == 0)
			a[i] = b[ind++];
	bool testok = 1;
	for (int i = 1; i <= n - 1; ++i)
		if (a[i] >= a[i + 1])
			testok = 0;
	printf(testok ? "No" : "Yes");
	return 0;
}
