class Solution {
private:
    struct Node{
        int u, v;
        int weight;
        Node(int _u, int _v, int _w){
            u = _u, v = _v, weight = _w;
        }
        bool operator < (const Node& a) const {
            return weight > a.weight; 
        }
    };
    int dirX[4] = {1, -1, 0, 0};
    int dirY[4] = {0, 0, 1, -1};
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int row = heights.size(), col = heights[0].size();
        vector<vector<int>> dist(row, vector<int>(col, INT_MAX));
        priority_queue<Node> que;
        que.push(Node(0, 0, 0));
        dist[0][0] = 0;
        while(!que.empty()){
            Node p = que.top();
            que.pop();
            if(p.u == row - 1 && p.v == col - 1){
                return p.weight;
            }
            for(int i = 0; i < 4; i++){
                int nu = dirX[i] + p.u;
                int nv = dirY[i] + p.v;
                if(nu >= 0 && nu < row && nv >= 0 && nv < col){
                    int w = abs(heights[nu][nv] - heights[p.u][p.v]);
                    int maxw = max(w, p.weight);
                    if(dist[nu][nv] > maxw){
                        dist[nu][nv] = maxw;
                        que.push(Node(nu, nv, maxw));
                    }
                }
            }
        }
        return 0;
    }
};