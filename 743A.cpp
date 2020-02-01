#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 3;
char f[N];
int n, a, b;

int main() {
	scanf("%d%d%d%s", &n, &a, &b, f + 1);
	if (a == b) { cout << 0; return 0; }
	if (a > b) swap(a, b);
	if (f[a] == f[b]) { cout << 0; return 0; }
	cout << 1;
	return 0;
}
