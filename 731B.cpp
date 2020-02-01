#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, a, cr = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a);
		int ta = a;
		a %= 2;
		if (cr == 1) {
			if (a == 1) {
				cr = 0;
			}
			else {
				if (ta == 0) {
					printf("NO");
					return 0;
				}
			}
		}
		else {
			if (a == 1) {
				cr = 1;
			}
		}
	}
	printf(cr ? "NO" : "YES");
	return 0;
}
