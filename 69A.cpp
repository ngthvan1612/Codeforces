#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, a = 0, b = 0, c = 0;
	for (cin >> n; n--;) {
		int x, y, z;
		cin >> x >> y >> z;
		a += x;
		b += y;
		c += z;
	}
	if (a == 0 && b == 0 && c == 0)
		cout << "YES";
	else cout << "NO";
	return 0;
}

