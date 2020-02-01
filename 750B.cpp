///created: 4/Jun/2019 20:18:55

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
#define db(x) cerr << "debug: " << #x << " = " << x << '\n';

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, x, cur = 0;
	string a;
	for (cin >> n; n--;) {
		cin >> x >> a;
		if ((cur == 0 && a[0] != 'S') || (cur == 20000 && a[0] != 'N')) {
			cout << "NO";
			return 0;
		}
		if (a[0] == 'N') cur -= x;
		if (a[0] == 'S') cur += x;
		if (cur < 0 || cur > 20000) {
			cout << "NO";
			return 0;
		}
	}
	cout << (cur == 0 ? "YES" : "NO");
	return 0;
}
