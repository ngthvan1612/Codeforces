#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	string s;
	cin >> n >> s;
	long long res = 0;
	s = ' ' + s;
	for (int i = 1; i <= n; ++i)
		if ((s[i] - '0') % 2 == 0)
			res = res + 1LL * i;
	cout << res;
	return 0;
}

