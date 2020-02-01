///created: 6/Jun/2019 14:45:28

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
	int n, k, i, j, rev = 1;
	cin >> n >> k;
	i = 1, j = n;
	k--;
	while (k-- > 0) {
		if (rev) cout << i++ << ' ';
		else cout << j-- << ' ';
		rev ^= 1;
	}
	if (rev) {
		for (int z = i; z <= j; ++z)
			cout << z << ' ';
	}
	else {
		for (int z = j; z >= i; --z)
			cout << z << ' ';
	}
	return 0;
}
