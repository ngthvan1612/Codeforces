///created: 30/May/2019 16:47:41

#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, v, k, tmp;
	vector<int> ans;
	scanf("%d%d", &n, &v);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &k);
		bool testok = 0;
		for (int j = 1; j <= k; ++j) {
			scanf("%d", &tmp);
			if (v > tmp)
				testok = 1;
		}
		if (testok)
			ans.push_back(i);
	}
	printf("%d\n", int(ans.size()));
	for (int v : ans)
		printf("%d ", v);
	return 0;
}
