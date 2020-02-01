///created: 10/Jun/2019 17:26:02

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

const int modulo = 1e9 + 7;

int main() {
	///ios::sync_with_stdio(0); cin.tie(0);
	int d = 1, abc = 0, n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int fd = int((3LL * abc) % (1LL * modulo));
		int fabc = int((2LL * abc + d) % (1LL * modulo));
		d = fd;
		abc = fabc;
	}
	cout << d;
	return 0;
}
