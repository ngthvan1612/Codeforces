///created: 6/Jun/2019 15:55:38

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
	int n, f[9];
	string s;
	cin >> n >> s;
	for (int i = 1; i <= 9; ++i)
		cin >> f[i];
	int ch = 0;
	for (int i = 0; i < n; ++i) {
		int d = s[i] - '0';
		if (d < f[d]) {
			ch = 1;
			s[i] = f[d] + '0';
		}
		if (d > f[d] && ch) break;
	}
	cout << s;
	return 0;
}
