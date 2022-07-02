class Solution {
private:
    vector<int> left, right;
    stack<int> stack;
    const int mod = 1e9 + 7;
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        left.resize(n);
        right.resize(n);
        // finding min values on left
        for(int i = 0; i < n; i++){
            while(!stack.empty() && arr[stack.top()] > arr[i]){
                stack.pop();
            }
            left[i] = stack.empty() ? i + 1 : i - stack.top();
            stack.push(i);
        }
        while(!stack.empty()) stack.pop();
        // finding min values on right
        for(int i = n - 1; i >= 0; i--){
            while(!stack.empty() && arr[stack.top()] >= arr[i]){
                stack.pop();
            }
            right[i] = stack.empty() ? n - i : stack.top() - i;
            stack.push(i);
        }
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum = (sum + (1ll * left[i] * right[i] * arr[i]) % mod) % mod;
        }
        return sum;
    }
};

// Time: O(N + N + N) = O(3N) ~ O(N), N = Number of elements
// Space: O(3N) ~ O(N)