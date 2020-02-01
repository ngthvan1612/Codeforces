#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
const int oo = 1e9 + 7;
const int modulo = 1e9 + 7;
template<typename T>
inline T sum(const T& a, const T& b) { return T((a % modulo + b % modulo) % modulo); }
template<typename T>
inline T mul(const T& a, const T& b) { return T((1LL * (a % (1LL * modulo)) * (b % (1LL * modulo))) % (1LL * modulo)); }
string to_string(string a) { return "\"" + a + "\""; }
#ifdef __LOCAL_DEBUG
#define debug(args...) { string __out = #args; replace(__out.begin(), __out.end(), ',', ' '); stringstream __out_ss(__out);\
istream_iterator<string> __it(__out_ss); _debug(__it, args); }
void _debug(istream_iterator<string> it) { }
template<typename T, typename... Args>
void _debug(istream_iterator<string> it, T a, Args... args){ cerr << *it << " = " << to_string(a) << '\n'; _debug(++it, args...); }
#else
#define debug(...)
#endif

const int N = 1e5 + 5;
ll tmp[N];
int top = 0;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  stack<int> st;
  tmp[++top] = 0LL;
  ll mz = (1LL << 32) - 1;
  debug(mz);
  tmp[0] = 1;
  while (n--) {
    string s;
    int x;
    cin >> s;
    if (s[0] == 'a') {
      tmp[top]++;
    }
    else if (s[0] == 'f') {
      cin >> x;
      st.push(x);
      tmp[++top] = 0;
    }
    else {
      tmp[top - 1] += 1LL * st.top() * tmp[top];
      st.pop();
      top--;
    }
    if (tmp[top] > mz) {
      cout << "OVERFLOW!!!\n";
      return 0;
    }
  }
  cout << tmp[1];
  return 0;
}
