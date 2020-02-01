#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> iill;
inline void add(int& a, const int& b, const int& modulo) {
	a += b;
	if (a > modulo) a -= modulo;
}
inline int mul(const int& a, const int& b, const int& modulo) {	return int((1LL * a * b) % (1LL * modulo)); }

const int N = 2e5 + 3;
char a[N];
bool vs[N] = {0};
int n;

int cntDepth() {
	int depth = 0, cnt = 0;
	for (int i = 1; i <= n; ++i)
		if (a[i] == '(') { cnt++; depth = max(depth, cnt); }
		else cnt--;
	assert(cnt == 0);
	return depth;
}

void solve() {
	scanf("%d", &n);
	scanf("%s", a + 1);
	int depth = cntDepth();
	int current = 0, max_depth = 0;
	stack<int> st;
	for (int i = 1; i <= n; ++i)
		if (a[i] == '(') {
			current++;
			max_depth = max(max_depth, current);
			st.push(i);
		}
		else {
			if (int(st.size()) <= depth / 2) {
				vs[st.top()] = 1;
				vs[i] = 1;
			}
			st.pop();
		}
	for (int i = 1; i <= n; ++i)
		printf("%d", vs[i]);
}

int main(int argc, char* argv[]) {
	if (argc >= 2) {
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	}
	solve();
	return 0;
}
