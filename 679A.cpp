///created: 1/Jul/2019 12:43:13

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

bool iprime(int v) {
	for (int i = 2; i * i <= v; ++i)
		if (v % i == 0)
			return false;
	return true;
}

void run(const vector<int>& q) {
	for (int i = 2; i <= 100; ++i) {
		int cnt = 0, pos = 0;
		bool ip = iprime(i), res = true;
		if (ip)
			cout << i << ' ';
		continue;
		for (int j = 0; j < int(q.size()); ++j)
			if (i % q[j] == 0) {
				cnt++;
				pos = j;
			}
		if (cnt > 1 || pos > 3)
			res = false;
		if (res != ip) {
			cout << "fail: " << i << '\n';
			cout << ip << ' ' << res << '\n';
			debug(cnt, pos);
			return;
		}			
	}
}

int main() {
	///ios::sync_with_stdio(0); cin.tie(0);
	vector<int> question;
	for (int i = 2; i <= 50; ++i)
		if (iprime(i))
			question.push_back(i);
	question.push_back(9);
	question.push_back(4);
	question.push_back(25);
	question.push_back(49);
	int cnt = 0;
	char res[4];
	for (int v : question) {
		printf("%d\n", v);
		fflush(stdout);
		scanf("%s", res);
		if (res[0] == 'y')
			cnt++;
	}
	printf((cnt <= 1) ? "prime\n" : "composite\n");
	fflush(stdout);
	return 0;
}
