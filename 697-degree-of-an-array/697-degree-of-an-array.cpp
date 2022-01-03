class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, vector<int>> count;
        int maxCount = -1;
        
        for(int i = 0; i < nums.size(); i++){
            if(!count.count(nums[i])){
                vector<int> val = {0, i, i};
                count[nums[i]] = val;
            }
            
            count[nums[i]][0]++;
            count[nums[i]][1] = min(count[nums[i]][1], i);
            count[nums[i]][2] = max(count[nums[i]][2], i);
            
            maxCount = max(maxCount, count[nums[i]][0]);
        }
        
        int answer = INT_MAX;
        
        for(auto &[key, val] : count){
            if(val[0] == maxCount){
                answer = min(answer, val[2] - val[1] + 1);
            }
        }
        
        return answer;
    }
};