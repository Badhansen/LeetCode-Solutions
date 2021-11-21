// @Author: KING-SEN
// Programming Language Used: C++

class Solution {
public:
    
    int maxProduct(vector<int>& nums) {
        int maxSoFar = nums[0];
        int minSoFar = nums[0];
        int answer = maxSoFar;
        
        for(int i = 1; i < nums.size(); i++){
            int current = nums[i];
            int tempMax = max({current, max(maxSoFar * current, minSoFar * current)});
            minSoFar = min({current, min(maxSoFar * current, minSoFar * current)});
            maxSoFar = tempMax;
            
            answer = max(answer, maxSoFar);
        }
        
        return answer;
    }
};

// Time Complexity: O(N), where N is the length of the array
// Space Complexity: O(1), Here we used only constant space
