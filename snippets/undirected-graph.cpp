template<typename Type>
struct Undigraph : Graph<Type> {
  using Graph<Type>::edges;
  using Graph<Type>::g;
  using Graph<Type>::n;

  Undigraph(int _n) : Graph<Type>(_n) {}

  void add(int from, int to, Type cost = 1) {
    assert(from >= 0 && from < n && to >= 0 && to < n);
    int id = (int) edges.size();
    g[from].push_back(id);
    g[to].push_back(from);
    edges.push_back({from, to, cost});
  }
};