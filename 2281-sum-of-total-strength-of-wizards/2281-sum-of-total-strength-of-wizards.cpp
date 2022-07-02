class Solution {
private:
    vector<long> prefsum, suffsum, doublePrefsum, doubleSuffsum;
    vector<int> left, right;
    stack<int> stack;
    const int mod = 1e9 + 7;
public:
    int totalStrength(vector<int>& strength) {
        int n = strength.size();
        prefsum.resize(n + 2, 0);
        suffsum.resize(n + 2, 0);
        doublePrefsum.resize(n + 2, 0);
        doubleSuffsum.resize(n + 2, 0);
        left.resize(n, -1);
        right.resize(n, n);
        for(int i = 1; i <= n; i++){
            prefsum[i] = (prefsum[i - 1] + strength[i - 1]) % mod;
            doublePrefsum[i] = (doublePrefsum[i - 1] + prefsum[i]) % mod;
        }
        for(int i = n; i >= 1; i--){
            suffsum[i] = (suffsum[i + 1] + strength[i - 1]) % mod;
            doubleSuffsum[i] = (doubleSuffsum[i + 1] + suffsum[i]) % mod;
        }
        for(int i = 0; i < n; i++){
            while(!stack.empty() && strength[stack.top()] >= strength[i]){
                right[stack.top()] = i;
                stack.pop();
            }
            stack.push(i);
        }
        while(!stack.empty()) stack.pop();
        for(int i = n - 1; i >= 0; i--){
            while(!stack.empty() && strength[stack.top()] > strength[i]){
                left[stack.top()] = i;
                stack.pop();
            }
            stack.push(i);
        }
        auto queryLeftSum = [&](int l,int r){
            if(l > r){
                return 0;
            }
            long long d = r - l + 1;
            long long toSubtract = (d * suffsum[r + 2]) % mod;
            long long ans = (doubleSuffsum[l + 1] - doubleSuffsum[r + 2] + mod) % mod;
            ans = (ans - toSubtract + mod) % mod;
            return (int)ans;
            
        };
        auto queryRightSum = [&](int l,int r){
            if(l > r){
                return 0;
            }
            long long d = r - l + 1;
            long long toSubtract = (d * prefsum[l]) % mod;
            long long ans = (doublePrefsum[r + 1] - doublePrefsum[l] + mod) % mod;
            ans = (ans - toSubtract + mod)% mod;
            return (int)ans;
        };
        long long ans = 0;
        for(int i = 0; i < n; i++){
            long long curr_min = strength[i];
            int l = left[i] + 1, r = right[i] - 1;
            long long right_sum = queryRightSum(i + 1,r);
            long long left_sum = queryLeftSum(l, i);
            long long curr_sum = (right_sum * (i - l + 1)) % mod;
            curr_sum = (curr_sum + (left_sum * (r - i +1)) % mod) % mod;
            long long curr_ans = (curr_sum * curr_min) % mod;
            ans = (ans + curr_ans) % mod;
        }
        return ans;
    }
    ~Solution(){
        prefsum.clear(), suffsum.clear(), doublePrefsum.clear(), doubleSuffsum.clear();
        left.clear(), right.clear();
        while(!stack.empty()) stack.pop();
    }
};