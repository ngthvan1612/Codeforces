#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 3;
int a[N], n;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	sort(a + 1, a + 1 + n);
	int sum = 0;
	for (int i = 1; i <= n - 1; ++i)
		sum += a[i];
	int e = a[n] - sum + 1;
	cout << e;	
	return 0;

