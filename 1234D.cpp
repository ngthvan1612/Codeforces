#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
char a[N];
int n, q, st[4 * N], rev[N];

void build(int id, int l, int r) {
	if (l == r) {
		st[id] = 1 << (a[l] - 'a');
		rev[l] = id;
	}
	else {
		int mid = (l + r) / 2;
		build(id * 2, l, mid);
		build(id * 2 + 1, mid + 1, r);
		st[id] = st[id * 2] | st[id * 2 + 1];
	}
}

void update(int pos, char c) {
	int id = rev[pos];
	st[id] = 1 << (c - 'a');
	id >>= 1;
	while (id) {
		st[id] = st[id * 2] | st[id * 2 + 1];
		id >>= 1;
	}
}

int get(int id, int l, int r, int u, int v) {
	if (v < l || r < u) return 0;
	if (u <= l && r <= v) return st[id];
	int mid = (l + r) / 2;
	return get(id * 2, l, mid, u, v) | get(id * 2 + 1, mid + 1, r, u, v);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> a + 1;
	n = int(strlen(a + 1));
	memset(st, 0, sizeof st);
	build(1, 1, n);
	cin >> q;
	while (q--) {
		int type;
		cin >> type;
		if (type == 1) {
			int pos;
			char c;
			cin >> pos >> c;
			update(pos, c);
		}
		else {
			int l, r;
			cin >> l >> r;
			cout << __builtin_popcount(get(1, 1, n, l, r)) << '\n';
		}
	}
	return 0;
}
