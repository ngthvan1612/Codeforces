#include <bits/stdc++.h>

using namespace std;

inline char lower(char c) { if ('A' <= c && c <= 'Z') c += 32; return c; }

int main() {
	string s;
	cin >> s;
	int n = int(s.length());
	int i = 0, j = n -1, diff = 0;
	while (i < j) {
		if (s[i] != s[j]) diff++;
		i++, j--;
	}
	if (diff == 1) cout << "YES";
	else if (n % 2 != 0 && diff == 0) cout << "YES";
	else cout << "NO";
	return 0;
}
