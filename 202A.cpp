#include <bits/stdc++.h>

using namespace std;

string minimize(string a, string b) {
	
}

int main() {
	string s, ans = "";
	cin >> s;
	int n = int(s.length());
	for (int st = 1; st < (1 << n); ++st) {
		string tmp = "", rev;
		for (int j = 0; j < n; ++j)
			if (st & (1 << j))
				tmp += char(s[j]);
		rev = tmp;
		reverse(rev.begin(), rev.end());
		if (rev == tmp) {
			ans = max(ans, rev);
		}
	}
	cout << ans;
	return 0;
}
