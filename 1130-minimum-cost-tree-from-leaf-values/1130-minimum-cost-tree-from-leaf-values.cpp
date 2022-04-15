class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int result = 0;
        vector<int> stack = {INT_MAX};
        for(auto &item : arr){
            while(stack.back() <= item){
                int minValue = stack.back();
                stack.pop_back();
                result += minValue * min(stack.back(), item);
            }
            stack.push_back(item);
        }
        for(int i = 2; i < stack.size(); i++){
            result += stack[i] * stack[i - 1];
        }
        return result;
    }
};

// Time: O(N), N = number of elements
// Space: O(N)