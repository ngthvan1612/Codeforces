///created: 8/Jun/2019 19:45:42

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
	int x, y, z;
	cin >> x >> y >> z;
	if (z == 0) {
		if (x == y) cout << "0";
		if (x < y) cout << "-";
		if (x > y) cout << "+";
	}
	else {
		int nx = x + z, ny = y + z;
		if (nx < y && ny > x) cout << "-";
		else if (ny < x && nx > y) cout << "+";
		else cout << "?";
	}
	return 0;
}
