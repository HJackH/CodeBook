int p[2 * MAXN];
int Manacher(const string &s) {
  string st = "@#";
  for (char c : s) {
    st += c;
    st += '#';
  }
  st += '$';
  int id = 0, mx = 0, ans = 0;
  for (int i = 1; i < st.length() - 1; i++) {
    p[i] = (mx > i ? min(p[2 * id - i], mx - i) : 1);
    for (; st[i - p[i]] == st[i + p[i]]; p[i]++);
    if (mx < i + p[i]) {
      mx = i + p[i];
      id = i;
    }
    ans = max(ans, p[i] - 1);
  }
  return ans;
}