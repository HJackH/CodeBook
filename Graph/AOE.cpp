struct AOE {
    // zero base
    const int INF = 1e9;
    struct Edge {
        int at;
        int cost;
    };

    struct Vertex {
        int early;
        int late;
        vector<Edge> from;
        vector<Edge> to;
    };

    int n;
    vector<Vertex> vertices;

    void init(int _n) {
        n = _n;
        vertices.clear();
        vertices.resize(_n);
        for (int i = 0; i < n; i++) {
            vertices[i].early = -1;
            vertices[i].late = INF;
        }
    }

    void addEdge(int from, int to, int cost) {
        // zero base
        vertices[from].to.push_back({to, cost});
        vertices[to].from.push_back({from, cost});
    }

    void dfsEarly(int now) {
        for (auto e : vertices[now].to) {
            if (vertices[e.at].early < vertices[now].early + e.cost) {
                vertices[e.at].early = vertices[now].early + e.cost;
                dfsEarly(e.at);
            }
        }
    }

    void dfsLate(int now) {
        for (auto e : vertices[now].from) {
            if (vertices[e.at].late > vertices[now].late - e.cost) {
                vertices[e.at].late = vertices[now].late - e.cost;
                dfsLate(e.at);
            }
        }
    }

    // may be slow?
    void printCritical(int now, vector<int> path) {
        if (vertices[now].to.size() == 0) {
            // critical path found
            for (auto i : path) {
                cout << i << ' ';
            }
            cout << '\n';
            return;
        }
        for (auto e : vertices[now].to) {
            if (vertices[e.at].early == vertices[e.at].late) {
                vector<int> tmp = path;
                tmp.push_back(e.at);
                printCritical(e.at, tmp);
            }
        }
    }

    int run() {
        for (int i = 0; i < n; i++) {
            if (vertices[i].from.size() == 0) {
                vertices[i].early = 0;
                dfsEarly(i);
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (vertices[i].to.size() == 0) {
                vertices[i].late = vertices[i].early;
                ans = max(ans, vertices[i].late);
                dfsLate(i);
            }
        }

        for (int i = 0; i < n; i++) {
            cout << "i = " << i << " early = " << vertices[i].early << " late = " << vertices[i].late << "\n";
        }

        for (int i = 0; i < n; i++) {
            if (vertices[i].from.size() == 0) {
                vector<int> path;
                path.push_back(i);
                printCritical(i, path);
            }
        }

        return ans;
    }    
};

int main() {
    AOE aoetest;
    int n, m;
    cin >> n >> m;
    aoetest.init(n);

    int a, b, w;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> w;
        aoetest.addEdge(a, b, w);
    }

    int res = aoetest.run();
    cout << "res = " << res << endl;
}