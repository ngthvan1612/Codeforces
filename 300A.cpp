#include <bits/stdc++.h>

using namespace std;

void pr(vector<int> a) {
	cout << a.size() << ' ';
	for (int v : a)
		cout << v << ' ';
	cout << '\n';	
}

int main() {
	int n;
	cin >> n;
	vector<int> pos, neg, zero;
	for (int i = 1; i <= n; ++i) {
		int a;
		cin >> a;
		if (a > 0) pos.push_back(a);
		else if (a < 0) neg.push_back(a);
		else zero.push_back(a);
	}
	vector<int> a, b, c;
	a.push_back(neg.back()); neg.pop_back();
	for (int v : pos)
		b.push_back(v);
	if (int(neg.size()) % 2 != 0) {
		c.push_back(neg.back());
		neg.pop_back();
	}
	for (int v : zero)
		c.push_back(v);
	for (int v : neg)
		b.push_back(v);
	pr(a);
	pr(b);
	pr(c);
	return 0;
}
