#include <bits/stdc++.h>

using namespace std;

int main() {
	string a, b, c;
	int f[256] = {0};
	cin >> a >> b >> c;
	for (char ch : a) f[ch]++;
	for (char ch : b) f[ch]++;
	for (char ch : c) f[ch]--;
	for (int i = 0; i < 256; ++i)
		if (f[i]) { cout << "NO"; return 0; }
	cout << "YES";
	return 0;
}
