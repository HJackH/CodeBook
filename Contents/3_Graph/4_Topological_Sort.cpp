// 0-base
// if ret.size < n -> cycle
int n;
vector<vector<int>> G;

vector<int> topoSort() {
  vector<int> indeg(n), ret;
  for (auto &li : G) {
    for (int x : li) {
      ++indeg[x];
    }
  }
  // use priority queue for lexic. largest ans
  queue<int> q;
  for (int i = 0; i < n; i++) {
    if (!indeg[i]) {
      q.push(i);
    }
  }
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    ret.pb(u);
    for (int v : G[u]) {
      if (--indeg[v] == 0) {
        q.push(v);
      }
    }
  }
  return ret;
}