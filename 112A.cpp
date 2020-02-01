#include <bits/stdc++.h>

using namespace std;

int main() {
	string a, b;
	cin >> a >> b;
	for (char &c : a)
		if ('a' <= c && c <= 'z') c -= 32;
	for (char &c : b)
		if ('a' <= c && c <= 'z') c -= 32;
	cout << strcmp(a.c_str(), b.c_str());
	return 0;
}

