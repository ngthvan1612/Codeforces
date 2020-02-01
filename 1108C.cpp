///created: 5/Jun/2019 20:59:19

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

int cnt[3][3] = {0}, n;
string t;

int get(char c) {
	if (c == 'B') return 0;
	if (c == 'G') return 1;
	if (c == 'R') return 2;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> t;
	for (int i = 0; i < n; ++i)
		cnt[i % 3][get(t[i])]++;
	string s = "RGB", p;
	sort(s.begin(), s.end());
	int ans = 1e9 + 7;
	do {
		int res = 0;
		for (int i = 0; i < 3; ++i) {
			res += cnt[i][0] + cnt[i][1] + cnt[i][2];
			res -= cnt[i][get(s[i])];
		}
		if (minimize(ans, res))
			p = s;
	}
	while (next_permutation(s.begin(), s.end()));
	cout << ans << '\n';
	for (int i = 0; i < n; ++i)
		cout << p[i % 3];
	return 0;
}
