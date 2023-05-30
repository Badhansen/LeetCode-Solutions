class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > ans;
        int siz = nums.size();
        int totalSize = pow(2, siz);
        for(int i = 0; i < totalSize; i++){
            vector<int> t;
            for(int j = 0; j < siz; j++){
                if(i & (1 << j)){
                    t.push_back(nums[j]);
                }
            }
            ans.push_back(t);
        }
        return ans;
    }
};