class Solution {
public:
    int n, m;
    bool visit[1000][1000];
    bool isValid(int i, int j){
        if(i >= 0 && i < n && j >= 0 && j < m) return 1;
        return 0;
    }
    void rec(vector<vector<int>> &image, int i, int j, int color, int newColor){
        if(isValid(i, j) && visit[i][j] == false){
            if(image[i][j] == color){
                image[i][j] = newColor;
                visit[i][j] = true;
                rec(image, i, j + 1, color, newColor);
                rec(image, i, j - 1, color, newColor);
                rec(image, i + 1, j , color, newColor);
                rec(image, i - 1, j, color, newColor);
            }
            return;
        }
        return;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        n = image.size();
        m = image[0].size();
        memset(visit, false, sizeof(visit));
        rec(image, sr, sc, image[sr][sc], newColor);
        return image;
    }
};