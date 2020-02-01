///created: 7/Jun/2019 15:44:20

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

int hor[] = { -1, 0, 1, 0 };
int ver[] = { 0, -1, 0, 1 };

char a[13][13] = {0};
int n, m;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%s", a[i] + 1);
	int ans = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (a[i][j] == 'W')
				for (int k = 0; k < 4; ++k)
					if (a[i + hor[k]][j + ver[k]] == 'P') {
						a[i + hor[k]][j + ver[k]] = '.';
						ans++;
						break;
					}
	cout << ans;
	return 0;
}
