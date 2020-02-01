#include <bits/stdc++.h>

using namespace std;

const int N = 51;
int f[N][N], n;
int a[N];

int Find(int v) {
	for (int i = 1; i <= n; ++i) {
		int cnt = 0, found = 0;
		for (int j = 1; j <= n; ++j)
			if (i != j && f[i][j] == v) {
				cnt++;
				found = 1;
			}
		if (cnt == n - v && found == 1)
			return i;
	}
	return -1;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			cin >> f[i][j];
	memset(a, -1, sizeof a);
	for (int i = 1; i <= n - 1; ++i)
		a[Find(i)] = i;
	for (int i = 1; i <= n; ++i)
		if (a[i] < 0)
			a[i] = n;
	for (int i = 1; i <= n; ++i)
		printf("%d ", a[i]);
	return 0;
}
