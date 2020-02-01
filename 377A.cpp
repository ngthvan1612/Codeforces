///created: 9/Jun/2019 19:22:03

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

const int hor[] = { 0, 0, -1, 1 };
const int ver[] = { -1, 1, 0, 0 };

int n, m, k, c = 0, cnt = 0;
char a[503][503] = {0};
bool vs[503][503] = {0};

void dfs(int u, int v) {
	if (u < 1 || u > n || v < 1 || v > m) return;
	cnt++;
	if (cnt <= k) {
		vs[u][v] = 1;
	}
	if (cnt > k) return;
	for (int k = 0; k < 4; ++k) {
		int x = hor[k] + u;
		int y = ver[k] + v;
		if (!vs[x][y] && a[x][y] == '.') {
			dfs(x, y);
		}
	}
}

int main() {
	///ios::sync_with_stdio(0); cin.tie(0);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; ++i) {
		scanf("%s", a[i] + 1);
		for (int j = 1; j <= m; ++j)
			c += (a[i][j] == '.');
	}
	k = c - k;
	db(k);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (a[i][j] == '.') {
				dfs(i, j);
				break;
			}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j)
			if (a[i][j] == '#')
				printf("#");
			else {
				if (vs[i][j])
					printf(".");
				else
					printf("X");
			}
		printf("\n");
	}
	return 0;
}
