class Solution {
private:
    vector<vector<int>> graph[105];
    struct Node{
        int u, w;
        Node(int u, int w){
            this->u = u;
            this->w = w;
        }
    };
    struct compare {
        bool operator()(const Node& a, const Node& b){
            return a.w > b.w;
        }
    };
public:
    int dijkstra(int src, int n){
        vector<int> dist(n + 1, INT_MAX);
        //priority_queue<Node, vector<Node>, compare> que;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
        que.push({0, src});
        dist[0] = 0; // as 0 node isn't available
        dist[src] = 0; 
        while(!que.empty()){
            auto node = que.top();
            que.pop();
            int source = node.second;
            int sweight = node.first;
            if(sweight > dist[source]){
                continue;
            }
            for(auto &vec : graph[source]){  
                int dest = vec[0];
                int dweight = vec[1];
                if (dist[dest] > dist[source] + dweight){
                    dist[dest] = dist[source] + dweight; 
                    que.push({dist[dest], dest}); 
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