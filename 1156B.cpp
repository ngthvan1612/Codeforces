#include <bits/stdc++.h>

using namespace std;

bool check(string s) {
	int n = int(s.length());
	for (int i = 0; i < n - 1; ++i)
		if (abs(s[i] - s[i + 1]) == 1) return false;
	return true;	
}

int main() {
	int T;
	string s;
	int a[101];
	for (cin >> T; T--;) {
		cin >> s;
		string c = "", l = "";
		for (char ch : s)
			if (ch % 2 == 0) c += ch;
			else l += ch;
		sort(c.begin(), c.end());
		sort(l.begin(), l.end());
		if (check(c + l)) cout << c + l << '\n';
		else if (check(l + c)) cout << l + c << '\n';
		else cout << "No answer\n";
	}
	return 0;
}
