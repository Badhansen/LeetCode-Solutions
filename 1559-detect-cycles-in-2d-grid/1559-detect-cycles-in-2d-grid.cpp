// see bfs solution

class Solution {
public:
    bool isValid(vector<vector<char>>& g,int u,int v,int prex,int prey){
        if (u < 0 || u >= g.size() || v < 0 || v >= g[0].size() || g[u][v] != g[prex][prey]){
            return false;
        }
        return true;
    }
    bool bfs(vector<vector<char>>& g,int r,int c,vector<vector<bool>>&vi){
        int offsets[] = {0, 1, 0, -1, 0};
        queue<pair<pair<int,int>,pair<int,int>>>q;
        q.push({{-1,-1},{r,c}});
        vi[r][c]=true;
        while(!q.empty()){
            int prex=q.front().first.first;
            int prey=q.front().first.second;
            int x = q.front().second.first;
            int y = q.front().second.second;
            q.pop();
            for (int k = 0; k < 4; k++) {
                int u = x + offsets[k], v = y + offsets[k + 1];
                if (isValid(g,u,v,x,y)) {
                    if(vi[u][v]){
                        if(prex!=u or prey!=v){
                            return true;
                        } 
                    }else{
                        vi[u][v] = true;
                        q.push({{x,y},{u, v}});
                    }
                }
            }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j]){
                    if(bfs(grid,i,j,vis)) return true;
                }
            }
        }
        return false;
    }
};