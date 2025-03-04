template<typename Type>
struct Forest : Graph<Type> {
  using Graph<Type>::edges;
  using Graph<Type>::g;
  using Graph<Type>::n;

  Forest(int _n) : Graph<Type>(_n) {}

  void add(int from, int to, Type cost = 1) {
    assert(from >= 0 && from < n && to >= 0 && to < n);
    int id = (int) edges.size();
    assert(id < n - 1);
    g[from].push_back(id);
    g[to].push_back(id);
    edges.push_back({from, to, cost});
  }
};