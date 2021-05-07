// 0-base;
const int MAXN = ;

struct Edge {
  int to;
  int cost;
  Edge(int v, int c) : to(v), cost(c) {}
};

int n, d = 0;
int d1[MAXN], d2[MAXN];
vector<Edge> G[MAXN];
// dfs(0, -1);
void dfs(int u, int from) {
  d1[u] = d2[u] = 0;
  for (auto e : G[u]) {
    if (e.to == from) {
      continue;
    }
    dfs(e.to, u);
    int t = d1[e.to] + e.cost;
    if (t > d1[u]) {
      d2[u] = d1[u];
      d1[u] = t;
    } else if (t > d2[u]) {
      d2[u] = t;
    }
  }
  d = max(d, d1[u] + d2[u]);
}