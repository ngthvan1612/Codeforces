#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	string s;
	cin >> n >> s;
	int r = 0, b = 0, res = 0;
	for (int i = 0; i < n;) {
		int j = i, tmp = 0;
		while (j < n && s[j] == s[i]) { ++j; tmp++; }
		i = j;
		res += tmp - 1;
	}
	cout << res;
	return 0;
}

