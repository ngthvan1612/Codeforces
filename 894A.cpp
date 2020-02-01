///created: 21/Jun/2019 18:54:12

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

int f[101][3] = {0};

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	string s;
	cin >> s;
	int n = int(s.length());
	s = ' ' + s;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < 3; ++j)
			f[i][j] = f[i - 1][j];
		if (s[i] == 'Q') {
			f[i][0]++;
			f[i][2] += f[i - 1][1];
		}
		else if (s[i] == 'A')
			f[i][1] += f[i - 1][0];
	}
	cout << f[n][2];
	return 0;
}
