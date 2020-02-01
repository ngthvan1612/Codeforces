#include <bits/stdc++.h>

using namespace std;

int m, n, a, b;

int main() {
	cin >> n >> m >> a >> b;
	int r1 = n * a;
	int r2 = n / m * b + min((n % m) * a, b);
	cout << min(r1, r2);
	return 0;
}
