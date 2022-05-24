// @Author: KING-SEN
// 1 last try

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> stack, ans(n, 0);
        for(int day = 0; day < n; day++){
            int currTemp = temperatures[day];
            while(!stack.empty() && temperatures[stack.back()] < currTemp){
                int prevDay = stack.back();
                stack.pop_back();
                ans[prevDay] = day - prevDay; 
            }
            stack.push_back(day);
        }
        return ans;
    }
};

// Time: O(N), N = Length of temperatures
// Space: O(N), for using stack