///created: 19/Jun/2019 22:43:20

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

const int N = 2e6 + 7;
int n, u, v;
char a[N], b[N];

int main() {
	///ios::sync_with_stdio(0); cin.tie(0);
	scanf("%d", &n);
	for (int _ = 1; _ <= n; ++_) {
		scanf("%s\n%s", a + 1, b + 1);
		u = int(strlen(a + 1));
		v = int(strlen(b + 1));
		vector<int> p, q;
		string f, g;
		for (int i = 1, t = 0, prev = 0; i <= u + 1; ++i) {
			if (i <= u && a[i] == prev) continue;
			p.push_back(i - t);
			t = i;
			prev = a[i];
			if (i <= u)
				f += a[i];
		}
		for (int i = 1, t = 0, prev = 0; i <= v + 1; ++i) {
			if (i <= v && b[i] == prev) continue;
			q.push_back(i - t);
			t = i;
			prev = b[i];
			if (i <= v)
				g += b[i];
		}
		bool ts = (p.size() == q.size());
		for (int i = 0; i < int(min(p.size(), q.size())); ++i)
			if (p[i] > q[i])
				ts = 0;
	 	printf((f == g) && ts ? "YES\n" : "NO\n");
	}
	return 0;
}
