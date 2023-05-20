class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> dist;
        for (int i = 0; i < equations.size(); ++i) {
            auto p = equations[i];
            double value = values[i];
            string from = p[0], to = p[1];
            dist[from][to] = value;
            dist[to][from] = 1 / value;
            dist[from][from] = dist[to][to] = 1.0;
        }
        for(auto& k : dist){
            for(auto& i : dist[k.first]){
                for(auto& j : dist[k.first]){
                    dist[i.first][j.first] = dist[i.first][k.first] * dist[k.first][j.first];
                }
            }
        }
        vector<double> res;
        for(auto& q : queries){
            string from = q[0], to = q[1];
            if(dist.count(from) && dist[from].count(to)){
                res.push_back(dist[from][to]);
            } 
            else{
                res.push_back(-1.0);
            }
        }
        return res;
    }
};