#include <bits/stdc++.h>

using namespace std;

int main() {
	string s;
	cin >> s;
	int a[7] = {0};
	for (char c : s) {
		if (c == 'h') a[1] = 1;
		if (c == 'e' && a[1]) a[2] = 1;
		if (c == 'l') {
			if (a[3]) a[4] = 1;
			if (a[2]) a[3] = 1;
		}
		if (c == 'o' && a[4]) a[5] = 1;
	}
	if (a[5]) cout << "YES";
	else cout << "NO";
	return 0;
}

