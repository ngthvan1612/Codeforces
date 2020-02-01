///created: 27/Jun/2019 11:47:08

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
	int n, fact[11];
	queue<int> q[2];
	cin >> n;
	for (int i = 0; i < 2; ++i) {
		int k, a;
		cin >> k;
		while (k--) {
			cin >> a;
			q[i].push(a);
		}
	}
	fact[0] = 1;
	for (int i = 1; i <= 10; ++i)
		fact[i] = fact[i - 1] * i;
	int cnt = 0;
	while (!q[0].empty() && !q[1].empty() && cnt <= fact[n]) {
		cnt++;
		int t0 = q[0].front(); q[0].pop();
		int t1 = q[1].front(); q[1].pop();
		if (t0 < t1) {
			debug(2, t0, t1);
			q[1].push(t0);
			q[1].push(t1);
		}
		else {
			debug(1, t1, t0);
			q[0].push(t1);
			q[0].push(t0);
		}
	}
	if (q[0].empty()) cout << cnt << ' ' << 2;
	else if (q[1].empty()) cout << cnt << ' ' << 1;
	else cout << -1;
	return 0;
}
