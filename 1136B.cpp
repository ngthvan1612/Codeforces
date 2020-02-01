#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	int res = 0;
	res += 2;
	res += 1;
	res += (n - 1) * 2;
	res += min(n - k, k - 1) + n - 1;
	cout << res;
	return 0;
}
