///created: 30/May/2019 15:06:06

#include <bits/stdc++.h>

using namespace std;

int mul(int a, int b, int modulo) {
	return int((1LL * a * b) % (1LL * modulo));
}

int fpow(int a, int k, int modulo) {
	if (k == 0) return 1;
	int tmp = fpow(a, k / 2, modulo);
	tmp = mul(tmp, tmp, modulo);
	if (k % 2) tmp = mul(tmp, a, modulo);
	return tmp;
}

int main() {
	int n;
	cin >> n;
	cout << fpow(1378, n, 10);
	return 0;
}
