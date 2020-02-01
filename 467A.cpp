#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, res = 0, p, q;
	for (cin >> n; n--;) {
		cin >> p >> q;
		if (q - p >= 2) res++;
	}
	cout << res;
	return 0;
}

