class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int miss = 0;
        int missing = 1;
        for(auto &el : arr){
            while(missing < el){
                miss++;
                if(miss == k)
                    return missing;
                missing++;

            }
            if(missing == el) missing++;
        }
        if(miss < k){
            missing += abs(miss - k + 1);
        }
        return missing;
    }
};