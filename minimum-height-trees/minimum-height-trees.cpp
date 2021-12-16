class Solution {
private:
    vector<vector<int>> graph;
    vector<int> inDegree;
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        graph.resize(n);
        inDegree.resize(n, 0);
        for(int i = 0; i < edges.size(); i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
            
            inDegree[edges[i][0]]++;
            inDegree[edges[i][1]]++;
        }
        
        vector<int> leaves;
        for(int i = 0; i < n; i++){
            if(inDegree[i] <= 1)
                leaves.push_back(i);
        }
        
        int lCount = leaves.size();
        
        while(lCount < n){
            vector<int> newLeaves;
            for(auto &l : leaves){
                for(auto &g : graph[l]){
                    inDegree[g]--;
                    if(inDegree[g] == 1)
                        newLeaves.push_back(g);
                }
            }
            
            lCount += newLeaves.size();
            leaves = newLeaves;
        }
        
        return leaves;
    }
};