///created: 7/Jul/2019 17:50:03

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
int a[N], n, m, k, id[N], vs[N] = {0};

bool cmp(int i, int j) { return a[i] > a[j]; }

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		id[i] = i;
	}
	sort(id + 1, id + 1 + n, cmp);
	for (int i = 1; i <= m * k; ++i)
		vs[id[i]] = 1;
	int i = 1;
	ll ans = 0;
	vector<int> st;
	while (i <= n) {
		int cnt, j = i + 1;
		ll cur = vs[i] * a[i];
		cnt = vs[i];
		while (j <= n && cnt <= m) {
			cnt += vs[j];
			if (cnt > m) {
				cnt--;
				break;
			}
			cur += vs[j] * a[j];
			++j;
		}
		st.push_back(j - 1);
		debug(i, j - 1, cur);
		ans += cur;
		i = j;
	}
	cout << ans << '\n';
	for (int i = 0; i < int(st.size()) - 1; ++i)
		cout << st[i] << ' ';
	return 0;
}
