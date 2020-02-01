#include <bits/stdc++.h>

using namespace std;

int main() {
	int a, b, n, need, who = 1;
	cin >> a >> b >> n;
	while (1) {
		if (who) need = __gcd(a, n);
		else need = __gcd(b, n);
		if (need > n) break;
		who ^= 1;
		n -= need;
	}
	cout << who;
	return 0;
}
