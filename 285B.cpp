///created: 6/Jun/2019 14:23:51

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

int n, a[100005], s, t, vs[100005] = {0};

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> s >> t;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	int cnt = 0, c = s;
	while (true) {
		if (vs[c] || c == t) break;
		vs[c] = 1;
		c = a[c];
		cnt++;
	}
	if (c == t) cout << cnt;
	else cout << -1;
	return 0;
}
