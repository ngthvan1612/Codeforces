///created: 30/May/2019 08:49:55

#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 1;
int a[N], b[N], n, m, cnt = 0, vs[N] = {0};

bool check2(int val) {
	for (int i = 1; i <= m; ++i)
		if (!vs[i] && a[i] != val && b[i] != val)
			return false;
	return true;
}

bool check1(int val) {
	memset(vs, 0, sizeof vs);
	cnt = 0;
	for (int i = 1; i <= m; ++i)
		if (a[i] == val || b[i] == val)
			vs[i] = 1;
	for (int i = 1; i <= m; ++i)
		if (!vs[i]) {
			if (check2(a[i]) || check2(b[i]))
				return true;
			return false;
		}
	return true;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i)
		scanf("%d%d", &a[i], &b[i]);
	printf((check1(a[1]) || check1(b[1])) ? "YES" : "NO");
	return 0;
}
