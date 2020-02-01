#include <bits/stdc++.h>

using namespace std;

int main() {
	int a = 0, b = 0, c = 0, n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int tmp; cin >> tmp;
		if (i % 3 == 1) a += tmp;
		else if (i % 3 == 2) b += tmp;
		else c += tmp;
	}
	int res = max(a, max(b, c));
	if (res == a) cout << "chest";
	else if (res == b) cout << "biceps";
	else cout << "back";
	return 0;
}

