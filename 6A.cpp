///created: 3/Jun/2019 22:23:33

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
#define db(x) cerr << "debug: " << #x << " = " << x << '\n';

int check(int a[3]) {
	sort(a, a + 3);
	if (a[2] == a[1] + a[0]) return 1;
	if (a[1] + a[0] > a[2] && a[2] + a[1] > a[0] && a[2] + a[0] > a[1]) return 0;
	return 2;
}

int main() {
	///ios::sync_with_stdio(0); cin.tie(0);
	int a[4], b[3];
	for (int i = 0; i < 4; ++i)
		cin >> a[i];
	int ans = 2;
	for (int s = 0; s < (1 << 4); ++s)
		if (__builtin_popcount(s) == 3) {
			int j = 0;
			for (int k = 0; k < 4; ++k)
				if ((1 << k) & s)
					b[j++] = a[k];
			ans = min(ans, check(b));
		}
	if (ans == 0) cout << "TRIANGLE";
	else if (ans == 1) cout << "SEGMENT";
	else cout << "IMPOSSIBLE";
	return 0;
}
