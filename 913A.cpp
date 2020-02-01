///created: 30/May/2019 16:05:52

#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	if (n <= 28) {
		cout << m % (1 << n);
	}
	else cout << m;
	return 0;
}
