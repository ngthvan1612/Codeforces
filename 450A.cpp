///created: 24/Jun/2019 16:49:15

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
template<class __Ty> bool maxi(__Ty& a, __Ty b) { return a <= b ? ((a = b) | 1) : (0); }
template<class __Ty> __Ty add(__Ty a, __Ty b) { return (a + b) % (__Ty(modulo)); }
template<class __Ty> __Ty sub(__Ty a, __Ty b) { __Ty m(modulo); return ((a - b) % m + m) % m; }

int process(queue<ii> Q, int m) {
	while (int(Q.size()) > 1) {
		ii t = Q.front(); Q.pop();
		if (t.second > m) {
			t.second -= m;
			Q.push(t);
		}
	}
	return Q.front().first;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m, amax = 0, a, pos;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a;
		if (maxi(amax, (a + m - 1) / m))
			pos = i;
	}
	cout << pos;
	return 0;
}
