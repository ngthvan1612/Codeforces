///created: 6/Jun/2019 20:57:40

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
	string a, b;
	cin >> a >> b;
	int n = int(a.length());
	int m = int(b.length());
	int ans = 0;
	for (int i = 0; i < n - m + 1;) {
		bool testok = 1;
		for (int j = 0; j < m; ++j)
			if (a[i + j] != b[j]) {
				testok = 0;
				break;
			}
		if (testok) {
			ans++;
			i += m;
		}
		else ++i;
		fprintf(stderr, "sw: %d\n", i);
	}
	cout << ans;
	return 0;
}
