class Solution {
private:
    vector<vector<int>> graph[105];
    struct Node{
        int u, w;
        Node(int u, int w){
            this->u = u;
            this->w = w;
        }
        bool operator < (const Node& a) const{
            return w > a.w;
        }
    };
public:
    int dijkstra(int src, int n){
        vector<int> dist(n + 1, INT_MAX);
        priority_queue<Node> que;
        que.push(Node(src, 0));
        dist[0] = dist[src] = 0; 
        while(!que.empty()){
            auto node = que.top();
            que.pop();
            //if(node[0] > dist[node[]])
            for(auto vec : graph[node.u]){  
                int v = vec[0];
                int w = vec[1];
                if (dist[v] > dist[node.u] + w){
                    dist[v] = dist[node.u] + w; 
                    que.push(Node(v, dist[v])); 
                } 
            } 
        }
        int maxTime = *max_element(dist.begin(), dist.end());
        if(maxTime != INT_MAX){
            return maxTime;
        }
        return -1;
    }
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        for(int i = 0; i < times.size(); i++){
            int u, v, w;
            u = times[i][0];
            v = times[i][1];
            w = times[i][2];
            graph[u].push_back({v, w});
        }
        return dijkstra(K, N);
    }
};