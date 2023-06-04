class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(!nums.size()) return 0;
        sort(nums.begin(), nums.end());
        int count = 1, maxCount = 1;
        for(int i = 1; i < nums.size(); i++){
            if (nums[i] != nums[i - 1]) {
                if (nums[i - 1] + 1 == nums[i]) {
                    count++;
                } else {
                    maxCount = max(maxCount, count);
                    count = 1;
                }
            }
        }
        return max(maxCount, count);
    }
};
/*
class Solution {
private:
    unordered_map<int, bool> seen;
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(!n) return 0;
        for(int index = 0; index < n; index++){
            seen[nums[index]] = index;
        }
        int longestStreak = 0;
        for(auto iterator : seen){
            if(!seen.count(iterator.first - 1)){
                int currNum = iterator.first;
                int currStreak = 1;
                while(seen.count(currNum + 1)){
                    currNum++;
                    currStreak++;
                }
                longestStreak = max(longestStreak, currStreak);
            }
        }
        return longestStreak;
    }
};
*/