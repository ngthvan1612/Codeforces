#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 1;
int a[3] = {0}, n;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int tmp;
		cin >> tmp;
		a[tmp]++;
	}
	vector<int> res;
	if (a[2]) res.push_back(2), a[2]--;
	if (a[1]) res.push_back(1), a[1]--;
	while (a[2]) res.push_back(2), a[2]--;
	while (a[1]) res.push_back(1), a[1]--;
	for (int v : res)
		cout << v << ' ';
	return 0;
}
