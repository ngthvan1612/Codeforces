#include <bits/stdc++.h>

using namespace std;

int main() {
	map<int, int> mp;
	int a[] = { 4, 8, 15, 16, 23, 42 };
	int mul[6][6];
	int qx[] = { 1, 2, 3, 4 };
	int qy[] = { 2, 3, 4, 5 };
	for (int i = 0; i < 6; ++i)
		mp[a[i]]++;
	for (int i = 0; i < 4; ++i) {
		printf("? %d %d\n", qx[i], qy[i]);
		fflush(stdout);
		scanf("%d", &mul[qx[i] - 1][qy[i] - 1]);
	}
	do {
		bool testok = 1;
		for (int i = 0; i < 4; ++i)
			if (a[i] * a[i + 1] != mul[i][i + 1])
				testok = 0;
		if (testok) {
			printf("! ");
			for (int i = 0; i < 6; ++i)
				printf("%d ", a[i]);
			break;
		}
	}
	while (next_permutation(a, a + 6));
	return 0;
}
