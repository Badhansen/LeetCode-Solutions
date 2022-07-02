class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size(), hot = 0;
        vector<int> ans(n, 0);
        for(int currday = n - 1; currday >= 0; currday--){
            int currTemp = temperatures[currday];
            if(currTemp >= hot){
                hot = currTemp;
                continue;
            }
            int days = 1;
            while(temperatures[currday + days] <= currTemp){
                days += ans[currday + days];
            }
            ans[currday] = days;
        }
        return ans;
    }
};

// Time: O(N), N = Length of temperatures
// Space: O(1)
/*   
      0  1  2  3 4  5   6  7
    [73, 74, 75, 71, 69, 72, 76, 73]   // for index 2, sum = 1 + ans[2 + 1] ~ 2 -> 3 + ans[2 + 3] ~ 1 -> 2 + ans[2 + 4]  
      1   1   4   2   1  1   0   0
               
*/

/*
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

*/