///created: 22/Jun/2019 20:31:42

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
const int modulo = 1e9 + 7;

template<class __Ty>
string to_string(__Ty a) {
	string res = "[ ";
	bool f = true;
	for (auto &p : a) {
		res += (f ? string("") : string(", ")) + to_string(p);
		f = false;
	}
	return res + " ]";
}
void _debug() { fprintf(stderr, "\n"); }
template<typename __Ty_head, typename... __Ty_tail>
void _debug(__Ty_head head, __Ty_tail... tail) {
	fprintf(stderr, "%s ", to_string(head).c_str());
	_debug(tail...);
}
#define debug(...) fprintf(stderr, "DEBUG [%s]: ", #__VA_ARGS__), _debug(__VA_ARGS__)

template<class __Ty> bool mini(__Ty& a, __Ty b) { return a > b ? ((a = b) | 1) : (0); }
template<class __Ty> bool maxi(__Ty& a, __Ty b) { return a < b ? ((a = b) | 1) : (0); }
template<class __Ty> __Ty add(__Ty a, __Ty b) { return (a + b) % (__Ty(modulo)); }
template<class __Ty> __Ty sub(__Ty a, __Ty b) { __Ty m(modulo); return ((a - b) % m + m) % m; }

struct st {
	int a[3];
};
st ans[33334];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int cnt[8] = {0}, n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		cnt[x]++;
	}
	for (int i = 1; i <= n / 3; ++i) {
		int t = 1, r = 0;
		while (t <= 7 && r < 3) {
			if (cnt[t]) {
				if (r == 0) ans[i].a[r++] = t, cnt[t]--;
				else {
					if (t % ans[i].a[r - 1] == 0 && t > ans[i].a[r - 1]) {
						ans[i].a[r++] = t;
						cnt[t]--;
					}
				}
			}
			++t;
		}
		if (r != 3) {
			printf("-1");
			return 0;
		}
	}
	for (int i = 1; i <= n / 3; ++i) {
		for (int j = 0; j < 3; ++j)
			printf("%d ", ans[i].a[j]);
		printf("\n");
	}
	return 0;
}
