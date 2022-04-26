class Solution {
public:
    vector<pair<long long, pair<int, int>>> edges;  
    vector<pair <int, int>> res; 
    vector<int> pr;
    int find(int x){
        if(x == pr[x]){
            return x;
        }
        return pr[x] = find(pr[x]);
    }
    void union_set(int x, int y){
        int p = find(x);
        int q = find(y);
        pr[p] = pr[q];
    }
    int kruskal(vector<pair<long long, pair<int, int>>>& edges){
        int x, y;
        long long cost, minimumcost = 0;
        for(int i = 0; i < edges.size(); i++){
            x = edges[i].second.first;
            y = edges[i].second.second;
            cost = edges[i].first;
            if (find(x) != find(y)){
                minimumcost += cost;
                union_set(x, y);
            }
        }
        return minimumcost;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int len = points.size();
        pr.resize(len);
        for(int i = 0; i < len; i++){
            pr[i] = i;
        }
        for(int i = 0; i < len; i++){
            for(int j = i + 1; j < len; j++){
                int weight = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({weight, {i, j}});
            }
        }
        sort(edges.begin(), edges.end());
        int answer = kruskal(edges);
        return answer;
    }
};