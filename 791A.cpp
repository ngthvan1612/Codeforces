#include <bits/stdc++.h>

using namespace std;

int main() {
	int a, b, x = 1;
	/// a.3^x >= b.2^x
	cin >> a >> b;
	while (pow(3, x) * a <= pow(2, x) * b) ++x;
	cout << x;
	return 0;
}

