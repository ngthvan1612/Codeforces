#include <bits/stdc++.h>

using namespace std;

int main() {
	string a, b, c = "";
	cin >> a >> b;
	for (int i = 0; i < int(a.length()); ++i)
		if (a[i] < b[i]) {
			cout << -1; return 0;
		}
		else c += min(a[i], b[i]);
	cout << c;
	return 0;
}
