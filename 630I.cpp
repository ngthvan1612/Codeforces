#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ll;
int n;
ll f[60][2];

int main() {
	memset(f, 0, sizeof f);
	cin >> n;
	f[0][0] = 1;
	for (int i = 1; i <= 2 * n - 2; ++i) {
		for (int j = i - 1; j >= max(0, i - n); --j)
			if (j != i - n) {
				f[i][0] += f[j][0] * 3;
				f[i][1] += f[j][1] * 3;
			}
			else {
				f[i][1] += f[j][0] * 3;
			}
	}
	cout << f[2 * n - 2][1] / 3 * 4;
	return 0;
}
