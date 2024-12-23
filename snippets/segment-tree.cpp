template<class Info>
struct SegmentTree {
    int n;
    vector<Info> tree;

    SegmentTree() : n(0) {}

    SegmentTree(int _n, Info _v = Info()) {
        init(_n, _v);
    }

    template<class T>
    SegmentTree(vector<T> &_init) {
        init(_init);
    }

    void init(int _n, Info _v = Info()) {
      init(vector(_n, _v));
    }

    Info merge(const Info A, const Info B) {
        return A + B;
    }

    template<class T>
    void init(vector<T> &_init) {
        n = (int) _init.size();
        int sz = (1 << (__lg(n - 1) + 1));
        tree.assign(2 * sz, Info());
        function<void(int, int, int)> build = [&](int v, int l, int r) {
            if (r - l == 1) {
                tree[v] = (Info) _init[l];
                return;
            }
            int mid = (l + r) / 2;
            build(2 * v + 1, l, mid);
            build(2 * v + 2, mid, r);
            tree[v] = merge(tree[2 * v + 1], tree[2 * v + 2]);
        };
        build(0, 0, n);
    }

    Info range_query(int l, int r) {
        return range_query(l, r, 0, 0, n);
    }

    Info range_query(int ql, int qr, int v, int l, int r) {
        if (qr <= l || r <= ql) {
            return (Info) 0;
        }
        if (ql <= l && r <= qr) {
            return tree[v];
        }
        int mid = (l + r) / 2;
        return merge(range_query(ql, qr, 2 * v + 1, l, mid), range_query(ql, qr, 2 * v + 2, mid, r));
    }

    template<class T>
    void modify(int id, T x) {
        modify(id, x, 0, 0, n);
    }

    template<class T>
    void modify(int id, T x, int v, int l, int r) {
        if (r - l == 1) {
            tree[v] = (Info) x;
            return;
        }
        int mid = (l + r) / 2;
        if (id < mid) {
            modify(id, x, 2 * v + 1, l, mid);
        } else {
            modify(id, x, 2 * v + 2, mid, r);
        }
        tree[v] = merge(tree[v * 2 + 1], tree[v * 2 + 2]);
    }

    Info query(int id) {
        return query(id, 0, 0, n);
    }

    Info query(int id, int v, int l, int r) {
        if (r - l == 1) {
            return tree[v];
        }
        int mid = (l + r) / 2;
        if (id < mid) {
            return query(id, 2 * v + 1, l, mid);
        } else {
            return query(id, 2 * v + 2, mid, r);
        }
    }
};
