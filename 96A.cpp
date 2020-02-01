#include <bits/stdc++.h>

using namespace std;

int main() {
	string s;
	cin >> s;
	int zero = 0, one = 0;
	bool testok = 0;
	for (char c : s)
		if (c == '1') {
			one++;
			zero = 0;
			if (one >= 7) testok = 1;
		}
		else {
			zero++;
			one = 0;
			if (zero >= 7) testok = 1;
		}
	cout << (testok ? "YES" : "NO");
	return 0;
}

