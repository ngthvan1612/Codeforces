///created: 20/Jun/2019 10:45:08

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

const int N = 1e5 + 5;
char a[N];
int m, f[N], n;

int main() {
	///ios::sync_with_stdio(0); cin.tie(0);
	f[0] = 0;
	scanf("%s", a + 1);
	n = int(strlen(a + 1));
	for (int i = 1; i < n; ++i)
		f[i] = f[i - 1] + (a[i] == a[i + 1]);
	for (scanf("%d", &m); m--;) {
		int l, r;
		scanf("%d%d", &l, &r);
		printf("%d\n", f[r - 1] - f[l - 1]); 
	}
	return 0;
}
