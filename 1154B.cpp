#include <bits/stdc++.h>

using namespace std;

int main() {
	int a[101], n, ps = 1e9 + 7, f[101];
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int m = 0; m <= 100; ++m) {
		set<int> st;
		for (int i = 1; i <= n; ++i)
			if (a[i] > m) st.insert(a[i] - m);
			else if (a[i] < m) st.insert(m - a[i]);
		if (st.size() == 1) ps = min(ps, *(st.begin()));
		else if (st.size() == 0) ps = min(ps, 0);
	}
	if (ps == 1e9 + 7) cout << -1;
	else cout << ps;
	return 0;
}
