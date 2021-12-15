// Programming Language Used: C++

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> st;
        for(auto &num : nums){
            if(st.count(num))
                return true;
            else
                st.insert(num);
        }
        return false;
    }
};

// Here N = Number of elements
// Time Complexity: O(N log N)
// Space Complexity: O(N)