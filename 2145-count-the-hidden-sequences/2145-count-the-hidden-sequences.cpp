class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long sum = 0, minDiff = 0, maxDiff = 0;
        for(auto &d : differences){
            sum += d;
            minDiff = min(minDiff, sum);
            maxDiff = max(maxDiff, sum);
        }
        return max(0LL, (upper - lower) - (maxDiff - minDiff) + 1);
    }
};