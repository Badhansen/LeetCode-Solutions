class Solution {
public:
    int candy(vector<int>& ratings) {
        int len = ratings.size();
        vector<int> candy(len, 1);
        for(int i = 0; i < len - 1; i++){
            if(ratings[i] < ratings[i + 1]){
                candy[i + 1] = candy[i] + 1;
            }
        }
        for(int i = len - 1; i > 0; i--){
            if(ratings[i - 1] > ratings[i]){
                candy[i - 1] = max(candy[i - 1], candy[i] + 1);
            }
        }
        int ans = 0;
        for(auto el : candy){
            ans += el;
        }
        
        return ans;
    }
};