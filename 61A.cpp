#include <bits/stdc++.h>

using namespace std;

int main() {
	string a, b, c;
	cin >> a >> b;
	int n = int(a.length());
	for (int i = 0; i < n; ++i)
		c += (a[i] != b[i] ? "1" : "0");
	cout << c;
}

