///created: 5/Jun/2019 19:37:47

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
#define db(x) cerr << "debug: " << #x << " = " << x << '\n';

int n, a[100005], ans = 0, vs[100005] = {0};

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	sort(a + 1, a + 1 + n);
	stack<int> st;
	for (int i = 1; i <= n; ++i)
		st.push(a[i]);
	for (int i = n; i >= 1; --i)
		if (a[i] < st.top()) {
			st.pop();
			ans++;
		}
	cout << ans;
	return 0;
}
