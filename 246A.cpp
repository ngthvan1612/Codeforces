#include <bits/stdc++.h>

using namespace std;

int a[51], n, t[51];

void Sort() {
	for (int i = 1; i <= n - 1; ++i)
		for (int j = i; j <= n - 1; ++j)
			if (a[j] > a[j + 1])
				swap(a[j], a[j + 1]);
}

bool Check() {
	for (int i = 1; i <= n - 1; ++i)
		if (a[i] > a[i + 1])
			return false;
	return true;
}

void GenTest() {
	for (int i = 1; i <= n; ++i)
		a[i] = t[i] = 100;
	a[n] = t[n] = 1;	
}

int main() {
	cin >> n;
	if (n <= 2) {
		cout << -1;
		return 0;
	}
	for (int i = 1; i <= n - 1; ++i) cout << 100 << ' ';
	cout << 1;
	return 0;
}
