class Solution {
private:
    vector<int> fibo;
    const int mod = 1e9 + 7;
public:
    int countHousePlacements(int n) {
        fibo.resize(n + 2, 0);
        fibo[0] = fibo[1] = 1;
        for(int i = 2; i <= n + 1; i++){
            fibo[i] = (fibo[i - 1] + fibo[i - 2]) % mod;
        }
        return (1ll * fibo[n + 1] * fibo[n + 1]) % mod;
    }
};