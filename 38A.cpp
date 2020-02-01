#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, f[101], a, b;
	cin >> n;
	for (int i = 1; i <= n - 1; ++i)
		cin >> f[i];
	cin >> a >> b;
	int res = 0;
	for (int i = a; i < b; ++i)
		res += f[i];
	cout << res;
	return 0;
}
