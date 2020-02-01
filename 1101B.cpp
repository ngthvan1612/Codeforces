///created: 6/Jun/2019 16:57:35

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
#define db(x) cerr << "debug: " << #x << " = " << x << '\n';
template<class __Ty> bool minimize(__Ty& a, __Ty b) {
	if (a > b) { a = b; return true; }
	return false;
}
template<class __Ty> bool maximize(__Ty& a, __Ty b) {
	if (a < b) { a = b; return true; }
	return false;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	string s;
	cin >> s;
	int n = int(s.length()), i = 0, j = n - 1, ans = 0;
	while (i < n && s[i] != '[') ++i;
	db(i);
	while (i < n && s[i] != ':') ++i;
	db(i);
	while (j >= 0 && s[j] != ']') --j;
	db(j);
	while (j >= 0 && s[j] != ':') --j;
	db(j);
	if (i >= j) cout << -1;
	else {
		for (int z = i + 1; z <= j - 1; ++z)
			if (s[z] == '|')
				ans++;
		cout << ans + 4;
	}
	return 0;
}
