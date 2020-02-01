#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	vector<string> a(n);
	for (string &str : a)
		cin >> str;
	for (int i = 0; i < n; ++i) {
		unsigned int pos = a[i].find("OO");
		if (pos != string::npos) {
			a[i].replace(pos, 2, "++");
			cout << "YES" << '\n';
			for (string str : a)
				cout << str << '\n';
			return 0;
		}
	}
	cout << "NO";
	return 0;
