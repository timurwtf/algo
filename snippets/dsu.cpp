struct DSU {
    int n;
    vector<int> p, s;

    DSU(int _n) : n(_n) {
        p.resize(n);
        s.assign(n, 1);
        iota(p.begin(), p.end(), 0);
    }

    int get(int x) {
        if (p[x] == x) {
            return x;
        }
        p[x] = get(p[x]);
        return p[x];
    }

    void unite(int x, int y) {
        x = get(x), y = get(y);
        if (s[x] > s[y]) {
            swap(x, y);
        }
        s[y] += s[x];
        p[x] = y;
    }
};
