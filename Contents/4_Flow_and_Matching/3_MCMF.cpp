// 0-base
const LL INF = 1e18;
const int MAXN = ;
struct Edge {
  int u, v;
  LL cost;
  LL cap;
  Edge(int _u, int _v, LL _c, LL _cap) : u(_u), v(_v), cost(_c), cap(_cap) {}
};
struct MCMF {     // inq times
  int n, pre[MAXN], cnt[MAXN];
  LL ans_flow, ans_cost, dis[MAXN];
  bool inq[MAXN];
  vector<int> G[MAXN];
  vector<Edge> edges;
  void init(int _n) {
    n = _n;
    edges.clear();
    for (int i = 0; i < n; i++) {
      G[i].clear();
    }
  }
  void add_edge(int u, int v, LL c, LL cap) {
    // directed
    G[u].pb(edges.size());
    edges.eb(u, v, c, cap);
    G[v].pb(edges.size());
    edges.eb(v, u, -c, 0);
  }
  bool SPFA(int st, int ed) {
    for (int i = 0; i < n; i++) {
      pre[i] = -1;
      dis[i] = INF;
      cnt[i] = 0;
      inq[i] = false;
    }
    queue<int> q;
    bool negcycle = false;

    dis[st] = 0;
    cnt[st] = 1;
    inq[st] = true;
    q.push(st);

    while (!q.empty() && !negcycle) {
      int u = q.front();
      q.pop();
      inq[u] = false;
      for (int i : G[u]) {
        int v = edges[i].v;
        LL cost = edges[i].cost;
        LL cap = edges[i].cap;

        if (dis[v] > dis[u] + cost && cap > 0) {
          dis[v] = dis[u] + cost;
          pre[v] = i;
          if (!inq[v]) {
            q.push(v);
            cnt[v]++;
            inq[v] = true;

            if (cnt[v] == n + 2) {
              negcycle = true;
              break;
            }
          }
        }
      }
    }

    return dis[ed] != INF;
  }
  LL sendFlow(int v, LL curFlow) {
    if (pre[v] == -1) {
      return curFlow;
    }
    int i = pre[v];
    int u = edges[i].u;
    LL cost = edges[i].cost;
  
    LL f = sendFlow(u, min(curFlow, edges[i].cap));

    ans_cost += f * cost;
    edges[i].cap -= f;
    edges[i ^ 1].cap += f;
    return f;
  }
  pair<LL, LL> run(int st, int ed) {
    ans_flow = ans_cost = 0;
    while (SPFA(st, ed)) {
      ans_flow += sendFlow(ed, INF);
    }
    return make_pair(ans_flow, ans_cost);
  }
};