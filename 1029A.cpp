///created: 5/Jun/2019 20:33:24

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
#define db(x) cerr << "debug: " << #x << " = " << x << '\n';

int main() {
	///ios::sync_with_stdio(0); cin.tie(0);
	int n, k, r;
	string t, ans;
	cin >> n >> k >> t;
	r = n;
	for (int i = 1; i < n; ++i) {
		bool testok = 1;
		for (int j = i; j < n; ++j)
			if (t[j] != t[j - i]) {
				testok = 0;
				break;
			}
		if (testok) {
			r = i;
			break;
		}
	}
	db(r);
	cout << t;
	for (int i = 1; i < k; ++i)
		for (int j = n - r; j < n; ++j)
			cout << t[j];
	return 0;
}
