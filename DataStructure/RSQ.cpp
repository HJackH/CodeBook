const int MAXN = 5e5 + 5;
long long a[MAXN];

struct Tree {
    struct Node {
        int l;
        int r;
        long long sum;
        long long lazy;
        void update(long long x) {
            sum += (r - l + 1) * x;
            lazy += x;
        }
    };

    Node st[MAXN * 4];

    void push_up(int x) {
        st[x].sum = st[x << 1].sum + st[(x << 1) + 1].sum;
    }

    void push_down(int x) {
        long long lazy = st[x].lazy;
        st[x << 1].update(lazy);
        st[(x << 1) + 1].update(lazy);
        st[x].lazy = 0;
    }

    void build(int x, int l, int r) {
        st[x].l = l;
        st[x].r = r;
        st[x].sum = 0;
        st[x].lazy = 0;
        if (l == r) {
            st[x].sum = a[r];
            return;
        }
        int mid = (r + l) >> 1;
        build(x << 1, l, mid);
        build((x << 1) + 1, mid + 1, r);
        push_up(x);
    }

    void update(int x, int l, int r, long long num) {
        int lt = st[x].l;
        int rt = st[x].r;
        if (l <= lt && rt <= r) {
            st[x].update(num);
            return;
        }
        push_down(x);
        int mid = (rt + lt) >> 1;
        if (l <= mid) {
            update(x << 1, l, r, num);
        }
        if (mid < r) {
            update((x << 1) + 1, l, r, num);
        }
        push_up(x);
    }

    long long query(int x, int l, int r) {
        int lt = st[x].l;
        int rt = st[x].r;
        if (l <= lt && rt <= r) {
            return st[x].sum;
        }
        push_down(x);
        int mid = (rt + lt) >> 1;
        long long ans = 0;
        if (l <= mid) {
            ans += query(x << 1, l, r);
        }
        if (mid < r) {
            ans += query((x << 1) + 1, l, r);
        }
        push_up(x);
        return ans;
    }
};

Tree rsq;