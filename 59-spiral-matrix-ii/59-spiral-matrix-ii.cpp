class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> vt(n, vector<int>(n, 0));
        int i = 0, x = 0, y = 0;
        int flag = 1;
        for(int  i = 1; i <= n * n; i++){
            vt[x][y] = i;
            if(flag == 1){
                y++;
                if(y == n || vt[x][y]){
                    y--, x++;
                    flag = 2;
                }
            }
            else if(flag == 2){
                x++;
                if(x == n || vt[x][y]){
                    x--, y--;
                    flag = 3;
                }
            }
            else if(flag == 3){
                y--;
                if(y == -1 || vt[x][y]){
                    y++, x--;
                    flag = 4;
                }
            }
            else{
                x--;
                if(x == -1 || vt[x][y]){
                    x++, y++;
                    flag = 1;
                }
            }
        }
        return vt;
        
    }
};