#include <bits/stdc++.h>

using namespace std;

int n, a[101], b[101], x;

void add(int& st, int v) {
	st |= (1 << (v - 1));
}

int main() {
	cin >> n >> x;
	for (int i = 1; i <= n; ++i)
		cin >> a[i] >> b[i];
	for (int i = 2; i <= n; ++i) {
		int st = 0;
		add(st, a[i]);
		add(st, 7 - a[i]);
		add(st, b[i]);
		add(st, 7 - b[i]);
		add(st, x);
		add(st, 7 - x);
		if (st != (1 << 6) - 1) {
			cout << "NO";
			return 0;
		}
		x = 7 - x;
	}
	cout << "YES";
	return 0;
}
