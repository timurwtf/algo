struct Edge {
    int from, to, cost;

    Edge() : from(-1), to(-1), cost(1) {}

    Edge(Edge const& other) {
        from = other.from;
        to = other.to;
        cost = other.cost;
    }

    Edge operator~() {
        Edge e = *this;
        swap(e.from, e.to);
        return e;
    }

    bool operator<(Edge const& other) {
        return cost < other.cost;
    }
};