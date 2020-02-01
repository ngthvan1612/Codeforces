///created: 6/Jun/2019 21:16:45

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

const int N = 1e5 + 3;
int n, m, a[N], cnt[N] = {0}, sz = 0;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= m; ++i)
		cin >> a[i];
	for (int i = 1; i <= m; ++i) {
		if (cnt[a[i]] == 0)
			sz++;
		cnt[a[i]]++;
		printf("%c", (sz == n) + '0');
		if (sz == n)
			for (int j = 1; j <= n; ++j) {
				cnt[j]--;
				if (cnt[j] == 0)
					sz--;
			}
	}
	return 0;
}
