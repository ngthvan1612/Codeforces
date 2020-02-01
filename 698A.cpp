///created: 21/Jun/2019 18:43:57

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

int a[101], f[101][3], n;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i)
		f[i][0] = f[i][1] = f[i][2] = 1e9 + 7;
	f[0][0] = f[0][1] = f[0][2] = 0;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < 3; ++j)
			f[i][0] = min(f[i][0], f[i - 1][j] + 1);
		if (a[i] == 1 || a[i] == 3)
			f[i][2] = min(f[i - 1][0], f[i - 1][1]);
	 	if (a[i] == 3 || a[i] == 2)
	 		f[i][1] = min(f[i - 1][0], f[i - 1][2]);
	}
	cout << min({f[n][0], f[n][1], f[n][2]});
	return 0;
}
