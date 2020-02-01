#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 3;
char a[N];
int n;

bool check(int i) {
	return (a[i] == a[i - 1] && a[i - 1] == a[i - 2]) || (a[i] == a[i - 2]);
	return false;
}

int main() {
	scanf("%d", &n);
	a[1] = 'a';
	a[2] = 'a';
	for (int i = 3; i <= n; ++i) {
		for (char c = 'a'; c <= 'c'; ++c) {
			a[i] = c;
			if (!check(i)) break;
		}
	}
	a[n + 1] = '\0';
	printf("%s", a + 1);
	return 0;
}
