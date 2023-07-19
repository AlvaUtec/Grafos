int dfs(int node) {
    int visCount = 1;
    visited[node] = true;
    for (auto neighbour: graph[node]) {
        if (!visited[neighbour]) {
            visCount += dfs(neighbour);
        }
    }
    return visCount;
}


