///created: 9/Jun/2019 09:05:25

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
	int n, m, rev = 1;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		if (i % 2 == 1)
			for (int i = 1; i <= m; ++i) cout << "#";
		else {
			if (rev) {
				for (int i = 1; i <= m - 1; ++i) cout << ".";
				cout << "#";
			}
			else {
				cout << "#";
				for (int i = 1; i <= m - 1; ++i) cout << ".";
			}
			rev ^= 1;
		}
		cout << "\n";
	}
	return 0;
}
