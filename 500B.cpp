///created: 8/Jul/2019 10:10:40

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

const int N = 305;
int a[N][N], p[N], ans[N], n;
bool vs[N] = {0};
vector<int> id[2];

void dfs(int u) {
	vs[u] = 1;
	for (int j = 0; j < 2; ++j)
		id[j].push_back(u);
	for (int v = 1; v <= n; ++v)
		if (a[u][v] && !vs[v]) {
			dfs(v);
		}
}

bool cmp(int i, int j) { return p[i] < p[j]; }

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> p[i];
	for (int i = 1; i <= n; ++i) {
		string line;
		cin >> line;
		for (int j = 1; j <= n; ++j)
			a[i][j] = line[j - 1] - '0';
	}
	for (int i = 1; i <= n; ++i)
		if (!vs[i]) {
			for (int j = 0; j < 2; ++j)
				id[j].clear();
			dfs(i);
			sort(id[0].begin(), id[0].end(), cmp);
			sort(id[1].begin(), id[1].end());
			for (int i = 0; i < int(id[0].size()); ++i) {
				ans[id[1][i]] = p[id[0][i]];
			}
		}
	for (int i = 1; i <= n; ++i)
		cout << ans[i] << ' ';
	return 0;
}
