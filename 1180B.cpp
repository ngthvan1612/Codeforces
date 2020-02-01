///created: 9/Jul/2019 20:37:00

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
int a[N], n, b[N];
ll ans1 = -1e18, ans2 = 1;

void bf() {
	for (int s = 0; s < (1 << n); ++s) {
		ll p = 1;
		for (int j = 0; j < n; ++j)
			if ((1 << j) & s)
				p *= (-a[j + 1] - 1);
			else
				p *= (a[j + 1]);
		ans1 = max(ans1, p);
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (a[i] >= 0)
			a[i] = -a[i] - 1;
	}
	if (n % 2) {
		a[0] = +1e9;
		int pos = 0;
		for (int i = 1; i <= n; ++i)
			if (a[i] != -1)
				if (a[i] < a[pos])
					pos = i;
		if (!pos) /// a[1] = a[2] = ... a[n] = -1
			pos = 1;
		a[pos] = -a[pos] - 1;
	}
	//bf();
	for (int i = 1; i <= n; ++i) {
		cout << a[i] << ' ';
		ans2 *= a[i];
	}
	return 0;
}
