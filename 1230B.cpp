#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	string s;
	cin >> n >> k >> s;
	if (n == 1) {
		if (k) cout << 0;
		else cout << s;
	}
	else {
		if (s[0] != '1' && k > 0) {
			s[0] = '1';
			k--;
		}
		for (int i = 1; i < n; ++i)
			if (s[i] != '0' && k > 0) {
				s[i] = '0';
				k--;
			}
		cout << s;
	}
	return 0;
}
