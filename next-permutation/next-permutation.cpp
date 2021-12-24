class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int cnt = 2;
        do{
            cnt--;
        }while(cnt && next_permutation(nums.begin(), nums.end()));
    }
};