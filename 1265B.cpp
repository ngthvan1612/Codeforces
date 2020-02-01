#include <bits/stdc++.h>
#include <windows.h>

using namespace std;

const int N = 2e5 + 5;
int bit[N];
int n, a[N], t, rev[N];
bool mask[N];
char res[N];

void update(int pos, int val) {
  for (int i = pos; i <= n; i += i & -i)
    bit[i] += val;
}

int get(int pos) {
  int res = 0;
  for (int i = pos; i; i -= i & -i)
    res += bit[i];
  return res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  for (cin >> t; t--;) {
    cin >> n;
    set<int> st;
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
      rev[a[i]] = i;
      st.insert(i);
      mask[i] = false;
    }
    res[1] = '1';
    mask[1] = true;
    int l = rev[1], r = rev[1];
    st.erase(1);
    for (int i = 2; i <= n; ++i) {
      if (!mask[i]) {
      if (rev[i] < l) {
        do {
            l--;
            st.erase(a[l]);
            mask[a[l]] = true;
          } while (l != rev[i]);
        }
        else {
          do {
            r++;
            st.erase(a[r]);
            mask[a[r]] = true;
          } while (r != rev[i]);
        }
      }
      if (!st.empty() && *st.begin() == i + 1 && int(st.size()) == n - i)
        res[i] = '1';
      else
        res[i] = '0';
    }
    res[n] = '1';
    res[n + 1] = 0;
    cout << res + 1 << '\n';
  }
  return 0;
}
