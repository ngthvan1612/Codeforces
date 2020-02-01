#include <bits/stdc++.h>

using namespace std;

int main() {
	int x, k, r;
	cin >> k >> r;
	for (x = 1; x <= 10; ++x)
		if (x * k % 10 == 0 || x * k % 10 == r) {
			cout << x;
			break;
		}
	return 0;
}
