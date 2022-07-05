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