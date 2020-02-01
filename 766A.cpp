#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	string a, b;
	cin >> a >> b;
	if (a == b) cout << -1;
	else cout << max(a.length(), b.length());
	return 0;
}
