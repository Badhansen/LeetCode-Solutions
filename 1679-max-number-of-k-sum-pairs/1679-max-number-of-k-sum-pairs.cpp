class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> have;
        for(auto &nb : nums){
            have[nb]++;
        }
        int count = 0;
        for(auto &nb : nums){
            if(have[nb] <= 0) continue;
            have[nb]--;
            int need = k - nb;
            if(have[need] > 0){
                count++, have[need]--;
            }
            else{
                have[nb]++;
            }
        }
        return count;
    }
};