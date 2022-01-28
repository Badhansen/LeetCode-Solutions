//@Author: KING-SEN
// Programming Language Used: C++

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> answer;
        int low = 0, high = numbers.size() - 1;
        while(low < high){
            int sum = numbers[low] + numbers[high];
            if(sum == target){
                return {low + 1, high + 1};
            }
            else if(sum < target) low++;
            else high--;
        }
        return {-1, -1};
    }
};

// Time Complexity: O(N), where N is the length of the array
// Space Complexity: O(1), we only use additional space to store two indices and the sum for this space complexity is O(1)
