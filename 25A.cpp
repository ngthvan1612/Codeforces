#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, even, odd, a[2] = {0};
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int tmp;
		cin >> tmp;
		a[tmp % 2]++;
		if (tmp % 2) odd = i;
		else even = i;
	}
	if (a[1] == 1) cout << odd;
	else cout << even;
	return 0;
}

