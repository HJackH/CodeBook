#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to;
    int cost;
    bool operator < (Edge const& other) const {
        return cost > other.cost;
    }
};

struct Vertex {
    int from;
    int cost;
};

const int INF = 1e9;
int N, M;
vector<vector<Edge>> adj;
vector<Vertex> vertices;

void init() {
    adj.resize(N);
    vertices.resize(N);
    for (int i = 0; i < N; i++) {
        adj[i].clear();
        vertices[i] = (Vertex) { -1, INF };
    }
}

void dijkstra(int source) {
    priority_queue<Edge, vector<Edge>> pq;
    vertices[source] = (Vertex) { source, 0 };
    pq.push((Edge) { source, 0 });

    while (!pq.empty()) {
        Edge etmp = pq.top();
        pq.pop();

        for (Edge i : adj[etmp.to]) {   //from etmp.to to i
            if (vertices[i.to].cost > vertices[etmp.to].cost + i.cost) {
                vertices[i.to].from = etmp.to;
                vertices[i.to].cost = vertices[etmp.to].cost + i.cost;
                pq.push((Edge) { i.to, vertices[i.to].cost });
            }
        }
    } 
}

void printV() {
    for (int i = 0; i < N; i++) {
        cout << '[' << i << ']' << '\t';
    }
    cout << endl;
    for (int i = 0; i < N; i++) {
        cout << vertices[i].from << '\t';
    }
    cout << endl;
    for (int i = 0; i < N; i++) {
        cout << vertices[i].cost << '\t';
    }
    cout << endl;
}

int main() {
    //N vertices & M edges
    cin >> N >> M;
    init();

    int a, b, w;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> w;
        adj[a].push_back((Edge) { b, w });
        adj[b].push_back((Edge) { a, w });
    }

    dijkstra(0);
    printV();
}