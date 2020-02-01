///created: 30/May/2019 16:09:54

#include <bits/stdc++.h>

using namespace std;

int main() {
	char a[104] = {0};
	scanf("%s", a + 1);
	int n = int(strlen(a + 1));
	int ans = 0, cur = 0;
	string vov = "AEIOUY";
	set<char> st(vov.begin(), vov.end());
	a[0] = a[n + 1] = 'A';
	for (int i = 1; i <= n + 1; ++i)
		if (st.find(a[i]) != st.end()) {
			ans = max(ans, i - cur);
			cur = i;
		}
	cout << ans;
	return 0;
}
