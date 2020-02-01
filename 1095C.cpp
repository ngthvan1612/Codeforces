///created: 8/Jul/2019 10:48:51

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
	int n, k, cnt[31] = {0}, c = 0;
	cin >> n >> k;
	for (int i = 0; i <= 30; ++i)
		if (n & (1 << i)) {
			cnt[i]++;
			c++;
		}
	int st = 30;
	while (c < k && st >= 1) {
		if (cnt[st] > 0) {
			cnt[st] -= 1;
			cnt[st - 1] += 2;
			c++;
		}
		else st--;
	}
	if (c < k || c > k) cout << "NO";
	else {
		cout << "YES\n";
		for (int i = 0; i <= 30; ++i) {
			for (int j = 0; j < cnt[i]; ++j)
				cout << (1 << i) << ' ';
		}
	}
	return 0;
}
