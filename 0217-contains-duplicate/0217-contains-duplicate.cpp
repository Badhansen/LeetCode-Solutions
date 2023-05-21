// Programming Language Used: C++

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> seen;
        for(auto &num : nums){
            if(seen.count(num)) {
                return true;
            }
            seen[num] = 1;
        }
        return false;
    }
};

// Here N = Number of elements
// Time Complexity: O(N)
// Space Complexity: O(N)