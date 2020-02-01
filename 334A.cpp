///created: 25/Jun/2019 10:26:54

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
	int n;
	cin >> n;
	int i = 1, j = n * n;
	vector<ii> cnt;
	while (i < j) {
		cnt.push_back(ii(i, j));
		++i;
		--j;
	}
	for (int i = 1; i <= n; ++i) {
		int sum = 0;
		for (int j = 0; j < n / 2; ++j) {
			int pos = (i - 1) * n / 2 + j;
			cout << cnt[pos].first << ' ' << cnt[pos].second << ' ';
			sum += cnt[pos].first + cnt[pos].second;
		}
		debug(sum);
		cout << '\n';
	}
	return 0;
}
