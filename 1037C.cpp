///created: 5/Jun/2019 18:43:38

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
#define db(x) cerr << "debug: " << #x << " = " << x << '\n';

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, ans = 0;
	string a, b;
	cin >> n >> a >> b;
	for (int i = 0; i < n; ++i) {
		if (a[i] != b[i]) {
			if (i + 1 < n && a[i + 1] != b[i + 1] && a[i] != a[i + 1]) {
				++i;
			}
			ans++;
		}
	}
	cout << ans;
	return 0;
}
