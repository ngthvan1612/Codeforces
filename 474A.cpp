#include <bits/stdc++.h>

using namespace std;

string a1 = "qwertyuiop";
string a2 = "asdfghjkl;";
string a3 = "zxcvbnm,./";
char L[256], R[256];

void Assign(string s) {
	for (int i = 1; i < int(s.length()); ++i)
		L[s[i]] = s[i - 1];
	for (int i = 0; i < int(s.length()) - 1; ++i)
		R[s[i]] = s[i + 1];
}

int main() {
	char type;
	string s;
	cin >> type >> s;
	Assign(a1);
	Assign(a2);
	Assign(a3);
	for (char &c: s)
		if (type == 'R') c = L[c];
		else c = R[c];
	cout << s;
	return 0;
}
