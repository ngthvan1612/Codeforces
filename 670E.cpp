///created: 11/Jul/2019 16:44:33

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

const int N = 5e5 + 5;
char a[N], s[N];
int n, m, p;
int pl[N], pr[N], l[N], r[N];

void build() {
	stack<int> st;
	memset(pl, 0, sizeof pl);
	memset(pr, 0, sizeof pr);
	r[0] = 1;
	l[n + 1] = n;
	for (int i = 1; i <= n; ++i) {
		l[i] = i - 1;
		r[i] = i + 1;
		if (a[i] == '(') st.push(i);
		else {
			int left = st.top(); st.pop();
			int right = i;
			pl[right] = left;
			pr[left] = right;
			debug(left, right);
		}
	}
}

void del(int w) {
	if (a[w] == ')')
		w = pl[w];
	int t = pr[w];
	///delete segment [w, t]
	int left = l[w];
	int right = r[t];
	r[left] = right;
	l[right] = left;
	if (right == n + 1) p = left;
	else p = right;
}

void print() {
	for (int i = r[0]; i <= n; i = r[i])
		printf("%c", a[i]);
	printf("\n");
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	scanf("%d%d%d\n%s\n%s", &n, &m, &p, a + 1, s + 1);
	build();
	for (int i = 1; i <= m; ++i) {
		if (s[i] == 'L') {
			p = l[p];
		}
		else if (s[i] == 'R') {
			p = r[p];
		}
		else {
			del(p);
		}
	}
	print();
	return 0;
}
