///created: 14/Jun/2019 23:06:03

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

const int N = 1e5 + 5;
char a[N];
int n, k, p[2][N];

int main() {
	///ios::sync_with_stdio(0); cin.tie(0);
	scanf("%d%d", &n, &k);
	scanf("%s", a + 1);
	p[0][0] = p[1][0] = 0;
	for (int i = 1; i <= n; ++i) {
		p[0][i] = p[0][i - 1];
		p[1][i] = p[1][i - 1];
		p[a[i] - 'a'][i]++;
	}
	int ans = 0;
	for (int j = 0; j < 2; ++j)
		for (int i = 1; i <= n; ++i)
			if ((i < n && a[i] == j + 'a' && a[i + 1] == (j ^ 1) + 'a') || i == n) {
				int w = lower_bound(p[j ^ 1], p[j ^ 1] + i + 1, p[j ^ 1][i] - k) - p[j ^ 1];
				ans = max(ans, i - w);
			}
	printf("%d", ans);
	return 0;
}
