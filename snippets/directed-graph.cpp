template<typename Type>
struct Digraph : Graph<Type> {
  using Graph<Type>::edges;
  using Graph<Type>::g;
  using Graph<Type>::n;

  Digraph(int _n) : Graph<Type>(_n) {}

  void add(int from, int to, Type cost = 1) {
    assert(from >= 0 && from < n && to >= 0 && to < n);
    int id = (int) edges.size();
    g[from].push_back(id);
    edges.push_back({from, to, cost});
  }

  Digraph<Type> inv() const {
    Digraph<Type> res(n);
    for (auto &edge : edges) {
      res.add(edge.to, edge.from, edge.cost);
    }
    return res;
  }
};