///created: 10/Jun/2019 09:32:31

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

const int N = 1 << 17 | 1;
int st[N << 2], bitw[N << 2], pos[N], a[N], n, m;

void build(int id, int l, int r) {
	if (l == r) {
		st[id] = a[l];
		pos[l] = id;
		bitw[id] = 1; ///xor
		return;
	}
	int mid = (l + r) / 2;
	build(id * 2, l, mid);
	build(id * 2 + 1, mid + 1, r);
	if (bitw[id * 2])
		st[id] = st[id * 2] | st[id * 2 + 1];
	else
		st[id] = st[id * 2] ^ st[id * 2 + 1];
	bitw[id] = bitw[id * 2] ^ 1;
}

void update(int p, int b) {
	int id = pos[p], tbit = 1;
	st[id] = b;
	id >>= 1;
	while (id) {
		if (tbit)
			st[id] = st[id * 2] | st[id * 2 + 1];
		else
			st[id] = st[id * 2] ^ st[id * 2 + 1];
		id >>= 1;
		tbit ^= 1;
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= (1 << n); ++i)
		scanf("%d", &a[i]);
	build(1, 1, 1 << n);
	while (m--) {
		int p, b;
		scanf("%d%d", &p, &b);
		update(p, b);
		printf("%d\n", st[1]);
	}	
	return 0;
}
