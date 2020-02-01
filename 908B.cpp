///created: 30/May/2019 18:39:21

#include <bits/stdc++.h>

using namespace std;

const int N = 53;
int n, m, sx, sy, p;
char a[N][N], b[103];
int v[] = { 0, 1, 2, 3 };
char f[] = "LRDU";
const int hor[] = { 1, -1, 0, 0 };
const int ver[] = { 0, 0, -1, 1 };

bool dfs(int u, int x, int y) {
	if (x < 1 || x > n || y < 1 || y > m) return false;
	if (a[x][y] == '#') return false;
	if (a[x][y] == 'E') return true;
	if (u == p + 1) return a[x][y] == 'E';
	int w = v[b[u] - '0'];
	return dfs(u + 1, x + hor[w], y + ver[w]);
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%s", a[i] + 1);
		for (int j = 1; j <= m; ++j)
			if (a[i][j] == 'S') {
				sx = i;
				sy = j;
			}
	}
	scanf("%s", b + 1);
	p = int(strlen(b + 1));
	int ans = 0;
	do {
		if (dfs(1, sx, sy))
			ans++;
		next_permutation(f, f + 4);
	}
	while (next_permutation(v, v + 4));
	printf("%d", ans);
	return 0;
}
