class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int> que(target.begin(), target.end());
        long long sum = accumulate(target.begin(), target.end(), 0ll);
        while(true){
            long long maxval = que.top();
            que.pop();
            sum -= maxval;

            if(maxval == 1 || sum == 1) 
                return true;
            
            if(maxval < sum || sum == 0 || maxval % sum == 0)
                return false;
            
            maxval = maxval % sum;
            sum += maxval;
            que.push(maxval);
        }
        return true;
    }
};

// Time: O(N log N), N = Length of the array
// Space: O(N)