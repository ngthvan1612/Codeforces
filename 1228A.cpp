#include <bits/stdc++.h>

using namespace std;

bool check(int w) {
	int mask = 0;
	while (w) {
		int v = w % 10;
		if (mask & (1 << v))
			return false;
		mask |= (1 << v);
		w /= 10;
	}
	return true;
}

int main() {
	int l, r;
	cin >> l >> r;
	for (int i = l; i <= r; ++i)
		if (check(i)) {
			cout << i;
			return 0;
		}
	cout << -1;
	return 0;
}
