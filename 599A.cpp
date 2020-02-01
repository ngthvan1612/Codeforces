///created: 9/Jun/2019 09:11:39

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
	int a, b, c;
	cin >> a >> b >> c;
	int r1 = a + b + c;
	int r2 = 2 * a + 2 * b;
	int r3 = 2 * min(a + c, b + c);
	cout << min(r1, min(r2, r3));
	return 0;
}
