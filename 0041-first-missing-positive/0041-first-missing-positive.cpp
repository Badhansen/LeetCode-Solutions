// static bool _foo = ios::sync_with_stdio(false);
// static ostream* _boo = cin.tie(NULL);

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        nums.push_back(0);
        int x, y, i;
        for(i = 0; i < nums.size(); i++){
            x = nums[i], y = 0;
            if(x != INT_MIN && x < nums.size()){
                y = nums[x];
                nums[x] = INT_MIN;
            }
            while(y != INT_MIN && y < nums.size()){
                x = nums[y];
                nums[y] = INT_MIN;
                y = x;
            }
        }
        for(i = 1; i <= nums.size(); i++){
            if(i == nums.size() || nums[i] != INT_MIN) return i;
        }
        return 1;
    }
};