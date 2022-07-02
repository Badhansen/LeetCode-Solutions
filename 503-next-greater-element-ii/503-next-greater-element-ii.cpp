class Solution {
private:
    stack<int> stack;
    vector<int> ans;
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        ans.resize(n, -1);
        for(int i = 0; i < 2 * n; i++){
            while(!stack.empty() && nums[i % n] > nums[stack.top() % n]){
                ans[stack.top()] = nums[i % n];
                stack.pop();
            }
            stack.push(i % n);
        }
        return ans;
    }
    ~Solution(){
        while(!stack.empty()) stack.pop();
        ans.clear();
    }
};