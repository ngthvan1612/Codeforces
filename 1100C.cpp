///created: 7/Jun/2019 21:24:26

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
	int n, r;
	cout << fixed << setprecision(10);
	cin >> n >> r;
	double ang = acos(-1) * (n - 2) / n;
	cout << - cos(ang / 2.0) * r / (cos(ang / 2.0) - 1);
	return 0;
}
