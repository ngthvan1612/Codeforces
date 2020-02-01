#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
char a[N];
int n;

int main() {
	scanf("%s", a + 1);
	n = int(strlen(a + 1));
	bool rep = false;
	for (int i = 1; i <= n; ++i)
		if ('b' <= a[i] && a[i] <= 'z') {
			rep = true;
			while (i <= n && 'b' <= a[i] && a[i] <= 'z') {
				a[i]--;
				++i;
			}
			break;
		}
	if (!rep) a[n] = 'z';
	printf("%s", a + 1);
	return 0;
}
