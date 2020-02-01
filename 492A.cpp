#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, t = 0, s = 0, i, res;
	cin >> n;
	for (i = 1;;++i) {
		t += i;
		s += t;
		if (s <= n) res = i;
		else break;
	}
	cout << res;
	return 0;
}
