///created: 9/Jun/2019 08:55:39

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
	int n;
	string s, ans;
	cin >> n >> s;
	int i = 0, j;
	while (i < n) {
		j = i + 1;
		while (j < n && s[j] == s[i]) ++j;
		if (j < n) {
			ans += s[i];
			ans += s[j];
			++j;
		}
		i = j;
	}
	cout << n - int(ans.size()) << '\n';
	cout << ans;
	return 0;
}
