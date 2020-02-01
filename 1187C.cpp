///created: 2/Jul/2019 10:09:59

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

vector<ii> fact[2];
int n, m, a[1003], f[1003] = {0};
int pa[1003] = {0};

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int t, l, r;
		cin >> t >> l >> r;
		fact[t].push_back(ii(l, r));
	}
	for (int i = 0; i < 2; ++i)
		sort(fact[i].begin(), fact[i].end());
	int tmp = 0;
	for (int i = 1; i <= n; ++i)
		a[i] = n - i + 1;
	for (ii p : fact[1]) {
		for (int j = p.first; j <= p.second; ++j)
			a[j] = a[p.first];
	}
	for (ii p : fact[0]) {
		bool ok = false;
		for (int j = p.first; j < p.second; ++j)
			if (a[j] > a[j + 1]) {
				ok = true;
				break;
			}
		if (!ok) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES\n";
	for (int i = 1; i <= n; ++i)
		cout << a[i] << ' ';
	return 0;
}
