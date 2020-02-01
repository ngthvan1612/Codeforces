#include <bits/stdc++.h>

using namespace std;

int main() {
	string s;
	getline(cin, s);
	int n = int(s.length());
	for (int i = 0; i < n - 1; ++i)
		for (int j = i + 1; j < n; ++j)
			if (s[i] != '+' && s[i] != ' ' && s[j] != '+' && s[j] != ' ')
				if (s[i] > s[j])
					swap(s[i], s[j]);
	cout << s;
	return 0;
}

