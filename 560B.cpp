///created: 2/Jul/2019 17:37:32

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
	int a[3], b[3];
	const int inp[] = { 2, 0, 1 };
	for (int i = 0; i < 3; ++i)
		cin >> a[inp[i]] >> b[inp[i]];
	for (int k = 0; k < 2; ++k) {
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < 2; ++j) {
				if ((a[2] >= a[0] + a[1]) && (b[2] >= max(b[0], b[1]))) {
					cout << "YES";
					return 0;
				}
				swap(a[1], b[1]);
			}
			swap(a[0], b[0]);
		}
		swap(a[2], b[2]);
	}
	cout << "NO";
	return 0;
}
