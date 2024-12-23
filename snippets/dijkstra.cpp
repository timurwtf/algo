vector<> dijkstra(int node, vector<vector<Edge>> &graph) {
    const long long BIG = 1e18;
    const int n = (int) graph.size();

    vector<long long> dist(n, BIG);
    vector<int> prev(n, -1);

    dist[node] = 0;

    vector<int> used(n);
    for (int i = 0; i < n; ++i) {
        int v = -1;

        for (int j = 0; j < n; ++j) {
            if (!used[j] && (v == -1 || dist[j] < dist[v])) {
                v = j;
            }
        }

        if (dist[v] == BIG) {
            break;
        }

        used[v] = 1;

        for (auto &[from, to, cost] : graph[v]) {
            if (dist[to] > dist[v] + cost) {
                dist[to] = dist[v] + cost;
                prev[to] = v;
            }
        }
    }

    return ;
} 