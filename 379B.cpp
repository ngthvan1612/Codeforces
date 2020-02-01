#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, a[301], sum = 0;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	int last = -1;
	bool can = true;
	for (int i = 1; i <= 300 && can; ++i) {
		if (a[1])
			printf("RL");
		for (int j = 1; j <= n; ++j) {
			if (a[j]) {
				a[j]--;
				printf("P");
			}
			if (j < n) printf("R");
		}
		if (a[n])
			printf("LR");
		for (int j = n; j >= 1; --j) {
			if (a[j]) {
				a[j]--;
				printf("P");
			}
			if (j > 1) printf("L");
		}
	}
	return 0;
}
