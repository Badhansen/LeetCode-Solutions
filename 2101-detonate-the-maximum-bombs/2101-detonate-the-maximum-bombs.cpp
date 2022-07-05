class Solution {
private:
    vector<vector<int>> graph;
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        graph.resize(n + 1);
        long long x, y, newx, newy, radius;
        int result = 0;
        for(int i = 0; i < n; i++){
            x = bombs[i][0], y = bombs[i][1], radius = (long long)bombs[i][2] * bombs[i][2];
            for(int j = 0; j < n; j++){
                newx = (x - bombs[j][0]), newy = (y - bombs[j][1]);
                if(newx * newx + newy * newy <= radius){
                    graph[i].push_back(j);
                }
            }
        }
        for(int i = 0; i < n && result < n; i++){
            vector<int> queue{i};
            unordered_set<int> connections{i};
            while(!queue.empty()){
                vector<int> tempQueue;
                for(int src : queue){
                    for(int k : graph[src]){
                        if(connections.insert(k).second)
                            tempQueue.push_back(k);
                    }
                }
                swap(queue, tempQueue);
            }
            result = max((int)connections.size(), result);
        }
        return result;
    }
    ~Solution(){
        for(int i = 0; i < graph.size(); i++){
            graph[i].clear();
        }
    }
};