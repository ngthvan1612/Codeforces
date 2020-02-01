///created: 23/Jun/2019 18:53:09

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
char a[N], b[N];
int n, cnt = 0;

int main() {
	///ios::sync_with_stdio(0); cin.tie(0);
	scanf("%s", a + 1);
	n = int(strlen(a + 1));
	for (int i = 1; i <= n; ++i)
		if (a[i] == '1')
			cnt++;
	for (int i = 1; i <= n; ++i)
		if (a[i] != '1') {
			if (a[i] == '2') {
				while (cnt-- > 0)
					printf("1");
				printf("2");
			}
			else
				printf("0");
		}
	while (cnt-- > 0)
		printf("1");
	return 0;
}