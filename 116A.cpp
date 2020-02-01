#include <bits/stdc++.h>

using namespace std;

int main() {
	int t, a, b, res = 0, cur = 0;
	for (cin >> t; t--;) {
		cin >> a >> b;
		cur += -a + b;
		res = max(res, cur);
	}
	cout << res;
	return 0;
}

