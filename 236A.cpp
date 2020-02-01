#include <bits/stdc++.h>

using namespace std;

int main() {
	string s;
	cin >> s;
	set<char> b(s.begin(), s.end());
	if (int(b.size()) % 2 == 1)
		cout << "IGNORE HIM!";
	else
		cout << "CHAT WITH HER!";
	return 0;
}

