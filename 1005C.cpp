///created: 23/Jun/2019 10:38:47

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

const int N = 12e4 + 5;

int n, m, cnt[N];
ll a[N], b[N];

void inc(ll v) {
	int k = lower_bound(b + 1, b + 1 + m, v) - b;
	if (b[k] != v) return;
	cnt[k]++;
}

int get(ll v) {
	int k = lower_bound(b + 1, b + 1 + m, v) - b;	
	if (b[k] == v)
		return cnt[k];
	return 0;
}

int main() {
	///ios::sync_with_stdio(0); cin.tie(0);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%I64d", &a[i]);
		b[i] = a[i];
	}
	sort(b + 1, b + 1 + n);
	m = unique(b + 1, b + 1 + n) - b - 1;
	b[m + 1] = -1;
	memset(cnt, 0, sizeof cnt);
	for (int i = 1; i <= n; ++i)
		inc(a[i]);
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		bool testok = false;
		for (int s = 0; s <= 31; ++s) {
			ll t = (1LL << s);
			if (t - a[i] == a[i]) {
				if (get(a[i]) > 1) {
					testok = true;
					break;
				}
			}
			else {
				if (get(a[i]) > 0 && get(t - a[i]) > 0) {
					testok = true;
					break;
				}
			}
		}
		if (!testok)
			ans++;
	}
	printf("%d", ans);
	return 0;
}
