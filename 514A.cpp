#include <bits/stdc++.h>

using namespace std;

int main() {
	long long n;
	cin >> n;
	vector<int> f;
	while (n) { f.push_back(n % 10); n /= 10; }
	reverse(f.begin(), f.end());
	for (int i = 0; i < int(f.size()); ++i)
		if (!(i == 0 && f[i] == 9))
			f[i] = min(f[i], 9 - f[i]);
	for (int v : f)
		cout << v;
	return 0;
}	
