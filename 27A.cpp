#include <bits/stdc++.h>

using namespace std;

int a[3003] = {0}, n;

int main() {
	cin >> n;
	int t;
	while (n--) {
		cin >> t;
		a[t] = 1;
	}
	for (int i = 1; i <= 3001; ++i)
		if (!a[i]) {
			cout << i;
			break;
		}
	return 0;
}
