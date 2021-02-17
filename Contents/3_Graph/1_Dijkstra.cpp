const long long INF = 1e18;
const int MAXN = ;
struct Edge {
  int at;
  long long cost;
  bool operator < (const Edge &other) const {
    return cost > other.cost;
  }
};

int n;
long long dis[MAXN];
vector<Edge> G[MAXN];

void init() {
  for (int i = 0; i < n; i++) {
    G[i].clear();
    dis[i] = INF;
  }
}
void Dijkstra(int st, int ed = -1) {
  priority_queue<Edge> pq;
  pq.push({ st, 0 });
  dis[st] = 0;
  while (!pq.empty()) {
    auto now = pq.top();
    pq.pop();
    if (now.at == ed) {
      return;
    }
    if (now.cost > dis[now.at]) {
      continue;
    }
    for (auto &e : G[now.at]) {
      if (dis[e.at] > now.cost + e.cost) {
        dis[e.at] = now.cost + e.cost;
        pq.push({ e.at, dis[e.at] });
      }
    }
  }
}