#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int pA;
    int pB;
    int cost;
    bool operator < (Edge const& other) const {
        return cost < other.cost;
    }
};

int N, M, total;
vector<int> parent;
vector<Edge> edges;
vector<Edge> results;

void init() {
    parent.resize(N);
    edges.resize(M);
    results.clear();
    total = 0;
    for (int i = 0; i < N; i++) {
        parent[i] = -1;
    }
}

int findSet(int x) {
    if (parent[x] < 0) {
        return x;
    }

    return parent[x] = findSet(parent[x]);
}

void uniSet(int a, int b) {
    a = findSet(a);
    b = findSet(b);
    if (a != b) {
        if (parent[a] > parent[b]) {
            swap(a, b);
        }
        parent[a] += parent[b];
        parent[b] = a;
    }
}

void kruskal() {
    sort(edges.begin(), edges.end());
    for (Edge e : edges) {
        if (findSet(e.pA) != findSet(e.pB)) {
            total += e.cost;
            results.push_back(e);
            uniSet(e.pA, e.pB);
        }
    }
}

int main() {
    cin >> N >> M;
    init();
    for (int i = 0; i < M; i++) {
        cin >> edges[i].pA >> edges[i].pB >> edges[i].cost;
    }
    kruskal();
    if (results.size() != (N - 1)) {
        cout << "no MST" << endl;
    } else {
        cout << total << endl;
    }
}