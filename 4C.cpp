///created: 2/Jun/2019 07:52:45

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<string, int> is;

const int mod = 1e5 + 3;
const int base = 31;

struct HashTable {
	vector<is> d[100004];
	int getHash(string a) {
		int ans = 0;
		for (char c : a)
			ans = (ans * base + (c - 'a')) % mod;
		return ans;
	}
	int push(string a) {
		int h = getHash(a);
		for (is &p : d[h])
			if (p.first == a) {
				return ++p.second;
			}
		d[h].push_back(is(a, 0));
		return 0;
	}
};

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	map<string, int> mp;
	cin >> n;
	HashTable hash;
	for (int i = 1; i <= n; ++i) {
		string tmp;
		cin >> tmp;
		int newv = hash.push(tmp);
		if (newv == 0) printf("OK\n");
		else printf("%s%d\n", tmp.c_str(), newv);
	}
	return 0;
}
