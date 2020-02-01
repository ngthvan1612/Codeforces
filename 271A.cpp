#include <bits/stdc++.h>

using namespace std;

bool check(int n) {
	bool s[10] = {0};
	while (n) {
		if (s[n % 10]) return 0;
		s[n % 10] = 1;
		n /= 10;
	}
	return 1;
}

int main() {
	int n;
	cin >> n;
	for (int i = n + 1; i <= 9999; ++i)
		if (check(i)) {
			cout << i;
			break;
		}
	return 0;
}

