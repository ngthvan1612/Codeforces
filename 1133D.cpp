#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 1;
int n, a[N], b[N], c[N];

struct fr {
	int n, d;
	fr(int _n = 0, int _d = 0) {
		n = _n; d = _d;
		int tmp = __gcd(n, d);
		n /= tmp;
		d /= tmp;
	}
};
bool operator<(const fr& l, const fr& r) { return l.n < r.n || (l.n == r.n && l.d < r.d); }

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &b[i]);
	map<fr, int> mp;
	int res = 0, tmp = 0;
	for (int i = 1; i <= n; ++i) {
		if (a[i] == 0) {
			if (b[i] == 0) tmp++;
		}
		else {
			mp[fr(-b[i], a[i])]++;
			res = max(res, mp[fr(-b[i], a[i])]);
		}
	}
	printf("%d", res + tmp);
	return 0;
}
