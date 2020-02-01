///created: 12/Jul/2019 20:16:36

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
const int modulo = 1e9 + 7;

#ifdef LOCAL_DEBUG_NTV1612
template<class __Ty>
string to_string(__Ty a) {
	string res = "[ ";
	bool f = true;
	for (auto &p : a) { res += (f ? string("") : string(", ")) + to_string(p); f = false;	}
	return res + " ]";
}
void _debug() { fprintf(stderr, "\n"); }
template<typename __Ty_head, typename... __Ty_tail>
void _debug(__Ty_head head, __Ty_tail... tail) { fprintf(stderr, "%s ", to_string(head).c_str()); _debug(tail...); }
#define debug(...) fprintf(stderr, "DEBUG [%s]: ", #__VA_ARGS__), _debug(__VA_ARGS__)
#else
#define debug(...) 0
#endif

template<class __Ty> bool mini(__Ty& a, __Ty b) { return a > b ? ((a = b) | 1) : (0); }
template<class __Ty> bool maxi(__Ty& a, __Ty b) { return a < b ? ((a = b) | 1) : (0); }
template<class __Ty> __Ty add(__Ty a, __Ty b) { return (a + b) % (__Ty(modulo)); }
template<class __Ty> __Ty sub(__Ty a, __Ty b) { __Ty m(modulo); return ((a - b) % m + m) % m; }

const int N = 2e5 + 5;
char s[N], t[N];
int n, a[N], m;
bool b[N];

bool check(int mid) {
	memset(b, 0, sizeof b);
	for (int i = 1; i <= mid; ++i)
		b[a[i]] = 1;
	int j = 1;
	for (int i = 1; i <= n && j <= m; ++i)
		if (!b[i] && s[i] == t[j])
			++j;
	return j == m + 1;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	scanf("%s\n%s", s + 1, t + 1);
	n = int(strlen(s + 1));
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	m = int(strlen(t + 1));
	int l = 1, r = n, ans = 0;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (check(mid)) {
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	cout << ans;
	return 0;
}
