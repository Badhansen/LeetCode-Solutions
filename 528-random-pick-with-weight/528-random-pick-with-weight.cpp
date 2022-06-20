// @Author: KING-SEN
// 1 last try

/*
    For [1,3] the probablity of choosing index 0 is 1/4, 1 is 3/4.
    Using Prefix sum I have converted the weight vector into a vector v:- [1, 4].
    If I generate a randon number and find the upper index which is greater than or equal to the prefix sum 
    if [1] then index 0 [2, 3, 4] -> index 1 25% and 75%
*/

class Solution {
private:
    vector<int> sum;
public:
    Solution(vector<int>& w) { // O(N), N = length of w
        srand(time(NULL));
        int n = w.size();
        sum.resize(n, 0);
        for(int i = 0; i < w.size(); i++){
            if(i == 0) sum[i] = w[i];
            else sum[i] += sum[i - 1] + w[i];
        }
    }
    
    int pickIndex() { // O(log N)
        return upper_bound(sum.begin(), sum.end(), rand() % sum.back()) - sum.begin();
    }
};


/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */