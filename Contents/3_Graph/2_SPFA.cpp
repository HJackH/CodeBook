// 0-base
const LL INF = 1e18;
const int MAXN = ;
struct Edge {
  int to;
  LL cost;
  Edge(int v, LL c) : to(v), cost(c) {}
};

int n;
LL dis[MAXN];
vector<Edge> G[MAXN];

void init() {
  for (int i = 0; i < n; i++) {
    G[i].clear();
    dis[i] = INF;
  }
}
bool SPFA(int st) {
  vector<int> cnt(n, 0);
  vector<bool> inq(n, false);
  queue<int> q;

  q.push(st);
  dis[st] = 0;
  inq[st] = true;
  while (!q.empty()) {
    int now = q.front();
    q.pop();
    inq[now] = false;
    for (auto &e : G[now]) {
      if (dis[e.to] > dis[now] + e.cost) {
        dis[e.to] = dis[now] + e.cost;
        if (!inq[e.to]) {
          cnt[e.to]++;
          if (cnt[e.to] > n) {
            // negative cycle
            return false;
          }
          inq[e.to] = true;
          q.push(e.to);
        }
      }
    }
  }
  return true;
}