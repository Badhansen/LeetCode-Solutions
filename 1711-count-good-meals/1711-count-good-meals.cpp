class Solution {
private:
    int count[(1 << 21) + 1];
    int mod = 1e9 + 7;
public:
    int countPairs(vector<int>& deliciousness) {
        int answer = 0;
        for(auto val : deliciousness){ // O(N * 21) ~ O(N)
            for(int i = 0; i <= 21; i++){
                int key = (1 << i) - val;
                if(key >= 0 && count[key]) answer = (answer + count[key]) % mod;
            }  
            count[val]++;
        }
        return answer % mod;
    }
};

// Time: O(N), N = number of elements
// Space: O(N)