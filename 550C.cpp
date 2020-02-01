#include <bits/stdc++.h>

using namespace std;

#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define ms(_mem, _value) memset((_mem), (_value), sizeof(_mem))
typedef long long ll;
typedef pair<int, int> ii;

int cf(char c) { return c - '0'; }

int Search(string s, int l) {
	int res = -1;
	if (l == 1) {
		for (int i = 0; i < int(s.length()); ++i)
			if (cf(s[i]) % 8 == 0) return cf(s[i]);
	}
	else if (l == 2) {
		for (int i = 0; i < int(s.length()); ++i)
			for (int j = i + 1; j < int(s.length()); ++j)
				if ((10 * cf(s[i]) + 1 * cf(s[j])) % 8 == 0)
					return 10 * cf(s[i]) + 1 * cf(s[j]);
	}
	else if (l == 3) {
		for (int i = 0; i < int(s.length()); ++i)
			for (int j = i + 1; j < int(s.length()); ++j)
				for (int k = j + 1; k < int(s.length()); ++k)
					if ((100 * cf(s[i]) + 10 * cf(s[j]) + 1 * cf(s[k])) % 8 == 0)
						return 100 * cf(s[i]) + 10 * cf(s[j]) + 1 * cf(s[k]);
	}
	return res;
}

int __solve() {
	string s;
	cin >> s;
	int r1 = Search(s, 1);
	int r2 = Search(s, 2);
	int r3 = Search(s, 3);
	r3 = max(r3, max(r2, r1));
	if (r3 == -1) cout << "NO";
	else cout << "YES\n" << r3;
	return -1;
}

int main(int argc, char** argv) {
	FAST_IO;
	if (argc > 1)
		assert(freopen(argv[1], "r", stdin));
	if (argc > 2)
		assert(freopen(argv[2], "w", stdout));
	int ___res = __solve();
	cerr << "\nTime elapsed: " << double(clock()) / CLOCKS_PER_SEC << "\nResult: " << ___res;
	return 0;
}
