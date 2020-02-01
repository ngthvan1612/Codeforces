#include <bits/stdc++.h>

using namespace std;

int main() {
	string s;
	cin >> s;
	bool isUpper = 1;
	int n = int(s.length());
	for (int i = 0 + 1; i < n; ++i)
		if ('A' <= s[i] && s[i] <= 'Z') isUpper = isUpper & 1;
		else isUpper = isUpper & 0;
	if (!isUpper) cout << s;
	else {
		if ('a' <= s[0] && s[0] <= 'z') s[0] -= 32;
		else s[0] += 32;
		for (int i = 1; i < n; ++i)
			s[i] += 32;
		cout << s;
	}
	return 0;
}

