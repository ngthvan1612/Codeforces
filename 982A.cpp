#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	char a[1005];
	scanf("%d%s", &n, a + 1);
	if (n == 1) {
		printf(a[1] == '1' ? "Yes" : "No");
		return 0;
	}
	if ((a[1] ^ a[2]) == 0) { printf("No"); return 0; }
	if ((a[n] ^ a[n - 1]) == 0) { printf("No"); return 0; }
	for (int i = 2; i <= n - 1; ++i)
		if (a[i] == '0') {
			if (a[i - 1] == '0' && a[i + 1] == '0') {
				printf("No");
				return 0;
			}
		}
		else {
			if (a[i - 1] == '1' || a[i + 1] == '1') {
				printf("No");
				return 0;
			}
		}
	printf("Yes");	
	return 0;
