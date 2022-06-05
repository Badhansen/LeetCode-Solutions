class Solution {
private:
    vector<int> power;
    unordered_map<int, int> count;
    int mod = 1e9 + 7;
public:
    void init(){
        power.resize(22);
        power[0] = 1;
        for(int i = 1; i <= 21; i++){
            power[i] = power[i - 1] * 2;
        }
    }
    int bigmod(int a, int b, int mod){ // O(log N)
        if(b == 0) return 1 % mod;
        int x = bigmod(a, b / 2, mod);
        x = (1ll * x * x) % mod;
        if(b % 2 == 1) x = (1ll * x * a) % mod;
        return x;
    }
    int countPairs(vector<int>& deliciousness) {
        init();
        for(auto &num : deliciousness){ // O(N)
            count[num]++;
        }
        int answer = 0;
        for(auto [key, val] : count){ // O(N * 21) ~ O(N)
            for(int i = 0; i <= 21; i++){
                int nkey = power[i] - key;
                if(count.count(nkey)){
                    if(key == nkey){
                        answer = (1ll * answer + (1ll * count[key] * (count[nkey] - 1))) % mod;
                    }
                    else{
                        answer = (1ll * answer + (1ll * count[key] * count[nkey])) % mod;
                    }
                }
            }  
        }
        answer = (1ll * answer * bigmod(2, mod - 2, mod)) % mod;
        return answer;
    }
};

// Time: O(N), N = number of elements
// Space: O(N)