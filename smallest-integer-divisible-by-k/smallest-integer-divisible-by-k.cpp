class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int num;
        int len = 1;
        int rem = 1;
        unordered_set<int> seen;
        while(rem % k != 0){
            num = rem * 10 + 1;
            rem = num % k;
            if(seen.find(rem) != seen.end())
                return -1;
            else 
                seen.insert(rem);
            len++;
        }
        return len;
    }
};

// Time: O(K)
// Space: O(K)