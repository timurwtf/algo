vector<int> bfs(int node, vector<vector<Edge>> &graph) {
    const int n = (int) graph.size();

    vector<int> dist(n, INF);
    vector<int> prev(n, -1);

    queue<int> q;

    dist[node] = 0;
    q.push(node);

    while (!q.empty()) {
        int v = q.front();

        q.pop();

        for (auto &[from, to, cost] : graph[v]) {
            if (dist[to] > dist[v] + 1) {
                dist[to] = dist[v] + 1;
                prev[to] = v;
                q.push(to);
            }
        }
    }

    return ;
}