vector<long long> dijkstra(int node, vector<vector<Edge>> &graph) {
    const long long BIG = 1e18;
    const int n = (int) graph.size();

    vector<long long> dist(n, BIG);
    vector<int> prev(n, -1);

    dist[node] = 0;
    using Pair = pair<long long, int>;
    priority_queue<Pair, vector<Pair>, greater<Pair>> pq;

    pq.push({0, node});

    while (!pq.empty()) {
        int v = pq.top().second;
        long long dv = pq.top().first;

        pq.pop();

        if (dv > dist[v]) {
            continue;
        }

        for (auto &[from, to, cost] : graph[v]) {
            if (dist[v] + cost < dist[to]) {
                dist[to] = dist[v] + cost;
                prev[to] = v;

                pq.push({dist[to], to});
            }
        }
    }

    return dist;
}
