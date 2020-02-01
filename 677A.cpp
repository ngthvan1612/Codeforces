#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, k, a, res = 0;
	for (cin >> n >> k; n--; ) {
		cin >> a;
		res += (a > k ? 2 : 1);
	}
	cout << res;
}

