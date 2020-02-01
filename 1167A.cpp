#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	string s;
	for (cin >> t; t--;) {
		int len;
		cin >> len >> s;
		int rmax = 0;
		reverse(s.begin(), s.end());
		for (int i = 0; i < int(s.length()); ++i)
			if (s[i] == '8') rmax = max(rmax, i + 1);
		if (rmax >= 11) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
