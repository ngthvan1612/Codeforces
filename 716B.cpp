///created: 28/Jun/2019 12:10:47

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

const int N = 5e4 + 5;
char a[N];
int n, cnt[26] = {0}, sz = 0;

void up(int i) {
	if (cnt[i] == 0) sz++;
	cnt[i]++;
}
void rem(int i) {
	if (cnt[i] == 1) sz--;
	cnt[i]--;
}

int main() {
	///ios::sync_with_stdio(0); cin.tie(0);
	scanf("%s", a + 1);
	n = int(strlen(a + 1));
	if (n < 26) printf("-1");
	else {
		int w = 0;
		bool ans = false;
		for (int i = 1; i <= n; ++i) {
			int pre = i - 26;
			if (pre >= 1) {
				if (a[pre] == '?')
					w--;
				else
					rem(a[pre] - 'A');
			}
			if (a[i] == '?')
				w++;
			else
				up(a[i] - 'A');
			if (sz + w == 26) {
				ans = true;
				for (int j = pre + 1, z = 0; j <= i; ++j)
					if (a[j] == '?') {
						while (z < 26 && cnt[z] > 0)
							++z;
						a[j] = z + 'A';
						++z;
					}
				for (int i = 1; i <= n; ++i)
					if (a[i] == '?')
						a[i] = 'A';
				break;
			}
		}
		printf(ans ? a + 1 : "-1");
	}
	return 0;
}
