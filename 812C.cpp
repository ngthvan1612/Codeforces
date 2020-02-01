///created: 13/Jul/2019 12:30:21

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

const int N = 1e5 + 5;
int n;
ll a[N], S, b[N];

bool check(int k, ll& res) {
	ll sum = 0;
	for (int i = 1; i <= n; ++i)
		b[i] = a[i] + 1LL * i * k;
	sort(b + 1, b + 1 + n);
	for (int i = 1; i <= k; ++i)
		sum += b[i];
	res = sum;
	return sum <= S;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> S;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	int l = 0, r = n, ans = -1;
	ll ansT = 0, res;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (check(mid, res)) {
			ans = mid;
			l = mid + 1;
			ansT = res;
		}
		else r = mid - 1;
	}
	cout << ans << ' ' << ansT;
	return 0;
}
