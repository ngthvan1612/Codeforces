#include <bits/stdc++.h>

using namespace std;

int main() {
	string a;
	getline(cin, a);
	int res = 0;
	set<char> st;
	for (char c : a)
		if ('a' <= c && c <= 'z')
			st.insert(c);
	cout << st.size();
	return 0;
}

