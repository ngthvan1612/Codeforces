#include <bits/stdc++.h>

using namespace std;

int main() {
	int x, res = 0;
	cin >> x;
	cout << x / 5 + 1 * (x % 5 != 0);
	return 0;
}

