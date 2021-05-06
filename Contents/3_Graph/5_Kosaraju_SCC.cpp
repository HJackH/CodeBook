// 0-base
int n;
vector<vector<int>> G, G2; // G2 = G rev
vector<bool> vis;
vector<int> s, color;
int sccCnt;
void dfs1(int u) {
  vis[u] = true;
  for (int v : G[u]) {
    if (!vis[v]) {
      dfs1(v);
    }
  }
  s.pb(u);
}
void dfs2(int u) {
  color[u] = sccCnt;
  for (int v : G2[u]) {
    if (!color[v]) {
      dfs2(v);
    }
  }
}
void Kosaraju() {
  sccCnt = 0;
  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      dfs1(i);
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    if (!color[s[i]]) {
      ++sccCnt;
      dfs2(s[i]);
    }
  }
}