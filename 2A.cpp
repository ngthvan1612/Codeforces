///created: 9/Jun/2019 18:40:31

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
#define db(x) cerr << "debug: " << #x << " = " << x << '\n';
template<class __Ty> bool minimize(__Ty& a, __Ty b) {
	if (a > b) { a = b; return true; }
	return false;
}
template<class __Ty> bool maximize(__Ty& a, __Ty b) {
	if (a < b) { a = b; return true; }
	return false;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	typedef pair<string, int> si;
	cin >> n;
	vector<si> a(n);
	map<string, int> mp;
	map<string, int> mark;
	int mk = 0;
	for (si &s : a) {
		cin >> s.first >> s.second;
		mp[s.first] += s.second;
	}
	int m = 0;
	for (si p : mp) {
		if (maximize(m, p.second))
			mark[p.first] = ++mk;
		else
			if (m == p.second)
				mark[p.first] = mk;
		mp[p.first] = 0;
	}
	db(m);
	for (si s: a) {
		mp[s.first] += s.second;
		if (mark[s.first] == mk && mp[s.first] >= m) {
			cout << s.first;
			return 0;
		}
	}
	return 0;
}
