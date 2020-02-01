#include <bits/stdc++.h>

using namespace std;

int main() {
	string tb, tmp;
	int testok = 0;
	cin >> tb;
	for (int i = 0; i < 5; ++i) {
		cin >> tmp;
		if (tmp[0] == tb[0] || tmp[1] == tb[1]) testok = 1;
	}
	if (testok) cout << "YES";
	else cout << "NO";
	return 0;
}

