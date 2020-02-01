///created: 4/Jun/2019 21:58:55

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
#define db(x) cerr << "debug: " << #x << " = " << x << '\n';

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	string s;
	cin >> s;
	stack<char> st;
	st.push('\0');
	int cnt = 0;
	for (char c : s) {
		if (st.top() == c) {
			cnt++;
			st.pop();
		}
		else
			st.push(c);
	}
	if (cnt % 2) cout << "Yes";
	else cout << "No";
	return 0;
}
