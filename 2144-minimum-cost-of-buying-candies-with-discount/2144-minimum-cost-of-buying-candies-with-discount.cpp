class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end());
        int ans = 0;
        while(cost.size()){
            if(cost.size() >= 3){
                ans += cost.back();
                cost.pop_back();
                ans += cost.back();
                cost.pop_back();
                cost.pop_back();
            }
            else if(cost.size() == 2){
                ans += cost.back();
                cost.pop_back();
                ans += cost.back();
                cost.pop_back();
            }
            else{
                ans += cost.back();
                cost.pop_back();
            }
        }
        return ans;
    }
};