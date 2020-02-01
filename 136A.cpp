#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, a[101];
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int tmp;
		cin >> tmp;
		a[tmp] = i;
	}
	for (int i = 1; i <= n; ++i)
		cout << a[i] << ' ';
	return 0;
}

