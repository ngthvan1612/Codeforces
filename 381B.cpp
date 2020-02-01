///created: 28/May/2019 13:40:19

#include <bits/stdc++.h>

using namespace std;

int n, a[5001] = {0};

int main() {
	scanf("%d", &n);	
	for (int i = 1; i <= n; ++i) {
		int tmp;
		cin >> tmp;
		a[tmp]++;
	}
	vector<int> f;
	for (int i = 1; i <= 5000; ++i)
		if (a[i]) {
			f.push_back(i);
			a[i]--;
		}
	for (int i = 5000; i >= 1; --i)
		if (a[i] && i != f.back()) {
			f.push_back(i);
		}
	printf("%d\n", int(f.size()));
	for (int v : f)
		printf("%d ", v);
	return 0;
}
