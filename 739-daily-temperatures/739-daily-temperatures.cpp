// @Author: KING-SEN
// 1 last try

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n);
        stack<int> stack;
        for(int day = 0; day < n; day++){
            while(!stack.empty() && temperatures[day] > temperatures[stack.top()]){
                ans[stack.top()] = day - stack.top();
                stack.pop();
            }
            stack.push(day);
        }
        return ans;
    }
};

// Time: O(N), N = Length of temperatures
// Space: O(N)