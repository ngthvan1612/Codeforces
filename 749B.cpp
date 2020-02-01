///created: 7/Jun/2019 14:25:43

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

ii calc(int x[3], int y[3]) {
	return ii(x[2] - x[0] + x[1], y[2] - y[0] + y[1]);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int x[3], y[3], s[3] = { 0, 1, 2 }, xp[3], yp[3];
	for (int i = 0; i < 3; ++i)
		cin >> x[i] >> y[i];
	cout << 3 << '\n';
	cout << x[2] - x[0] + x[1] << ' ' << y[2] - y[0] + y[1] << '\n';
	cout << x[1] - x[2] + x[0] << ' ' << y[1] - y[2] + y[0] << '\n';
	cout << x[0] - x[1] + x[2] << ' ' << y[0] - y[1] + y[2];
	return 0;
}
