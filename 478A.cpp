#include <bits/stdc++.h>

using namespace std;

int main() {
	int sum = 0, a;
	for (int i = 1; i <= 5; ++i) {
		cin >> a;
		sum += a;
	}
	if (sum % 5 == 0 && sum != 0) cout << sum / 5;
	else cout << -1;
	return 0;
}
