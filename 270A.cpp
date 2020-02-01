#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	for (cin >> t; t--;) {
		int n;
		cin >> n;
		if (360 % (180 - n) == 0) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
