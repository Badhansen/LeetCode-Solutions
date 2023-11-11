class Graph {
private:
    int n;
    vector<vector<pair<int, int>>> graph;
    int dijkstra(int src, int dest) {
        vector<int> dist(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
        que.push({0, src});
        dist[src] = 0;
        while (!que.empty()) {
            auto node = que.top();
            que.pop();
            int source = node.second;
            int sWeight = node.first;
            if (sWeight > dist[source]) {
                continue;
            }
            for (auto &vec : graph[source]) {
                int dest = vec.first;
                int dWeight = vec.second;
                if (dist[dest] > dist[source] + dWeight) {
                    dist[dest] = dist[source] + dWeight;
                    que.push({dist[dest], dest});
                }
            }
        }
        if (dist[dest] == INT_MAX) {
            return -1;
        } 
        return dist[dest];
    }
public:
    Graph(int n, vector<vector<int>>& edges) {
        this->n = n;
        graph.resize(n);
        for (auto &e : edges) {
            graph[e[0]].push_back({e[1], e[2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        graph[edge[0]].push_back({edge[1], edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        return dijkstra(node1, node2);
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */