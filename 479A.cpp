#include <bits/stdc++.h>

using namespace std;

int main() {
	int a, b, c, res = 0;
	cin >> a >> b >> c;
	res = max(res, a + b + c);
	res = max(res, a + b * c);
	res = max(res, a * b + c);
	res = max(res, a * b * c);
	res = max(res, (a + b) * c);
	res = max(res, a * (b + c));
	cout << res;
	return 0;
}

