#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, cnt[256] = {0};
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		string tmp;
		cin >> tmp;
		cnt[tmp[0]]++;
	}
	int res = 0;
	for (int i = 'a'; i <= 'z'; ++i) {
		int tmp = cnt[i] / 2;
		res += tmp * (tmp - 1) / 2;
		tmp = cnt[i] - tmp;
		res += tmp * (tmp - 1) / 2;
	}
	cout << res;
	return 0;
}
