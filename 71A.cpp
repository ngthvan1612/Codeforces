#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	string s;
	for (cin >> n; n--;) {
		cin >> s;
		if (int(s.length()) <= 10) cout << s << '\n';
		else {
			cout << s[0] << to_string(int(s.length()) - 2) << s[s.length() - 1] << '\n';
		}
	}
	return 0;
}
