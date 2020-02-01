///created: 10/Jul/2019 14:30:26

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

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int q, n;
	for (cin >> q; q--;) {
		cin >> n;
		vector<int> a(n);
		for (int &x : a) cin >> x;
		sort(a.begin(), a.end());
		vector<int> f;
		int cur = -1, cnt = 0;
		a.push_back(int(1e9));
		n++;
		for (int i = 0; i < n; ++i)
			if (cur == a[i]) cnt++;
			else {
				if (i != 0)
					f.push_back(cnt);
				cur = a[i];
				cnt = 1;
			}
		sort(f.rbegin(), f.rend());
		int ans = 0, r = f[0] + 1;
		for (int &x : f) {
			r = max(0, min(r - 1, x));
			ans += r;
		}
		cout << ans << '\n';
	}
	return 0;
}
