#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, p, q, tmp;
	set<int> st;
	cin >> n;
	cin >> p;
	for (int i = 0; i < p; ++i) { cin >> tmp; st.insert(tmp); }
	cin >> q;
	for (int i = 0; i < q; ++i) { cin >> tmp; st.insert(tmp); }
	if (int(st.size()) == n)
		cout << "I become the guy.";
	else
		cout << "Oh, my keyboard!";
}

