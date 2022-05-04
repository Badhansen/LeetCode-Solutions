class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        vector<int> answer;
        unordered_map<int, vector<int>> hRec;
        for(auto &rec : rectangles){
            hRec[rec[1]].push_back(rec[0]);
        }
        for(int i = 1; i <= 100; i++){
            sort(hRec[i].begin(), hRec[i].end());
        }
        for(auto p : points){
            int count = 0, x = p[0], y = p[1];
            for(int i = y; i <= 100; i++){
                if(!hRec.count(i)){
                    continue;
                }
                int telement = lower_bound(hRec[i].begin(), hRec[i].end(), x) - hRec[i].begin();
                count += hRec[i].size() - telement; 
            }
            answer.push_back(count);
        }
        return answer;
    }
};