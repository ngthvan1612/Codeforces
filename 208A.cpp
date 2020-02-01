#include <bits/stdc++.h>

using namespace std;

int main() {
	string s;
	cin >> s;
	int n = int(s.length());
	string res;
	s += "...";
	for (int i = 0; i < n;) {
		if (s[i] == 'W' && s[i + 1] == 'U' && s[i + 2] == 'B') {
			i += 3;
			if (int(res.length()) && res[res.length() - 1] != ' ')
				res += " ";
		}
		else { res += s[i]; i += 1; }
	}
	cout << res;
	return 0;
}

