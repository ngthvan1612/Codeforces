#include <bits/stdc++.h>

using namespace std;

const int hor[] = { 0, 0, 1, -1, 0 };
const int ver[] = { 1, -1, 0, 0, 0 };
int n, a[53][53];

void process(int x, int y) {
	int res = 1;
	for (int k = 0; k < 5; ++k) {
		res &= a[hor[k] + x][ver[k] + y];
	}
	if (res)
		for (int k = 0; k < 5; ++k)
			a[hor[k] + x][ver[k] + y] = 0;
}

int main() {
	cin >> n;
	memset(a, 0, sizeof a);
	for (int i = 1; i <= n; ++i) {
		string tmp;
		cin >> tmp;
		for (int j = 1; j <= n; ++j)
			if (tmp[j - 1] == '.')
				a[i][j] = 1;
	}
	for (int i = 2; i <= n - 1; ++i)
		for (int j = 2; j <= n - 1; ++j)
			process(i, j);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			if (a[i][j]) { cout << "NO"; return 0; }
	cout << "YES";
	return 0;
}
