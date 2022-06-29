class Solution {
private:
    const int p = 31;
    const int mod = 1e9 + 7;
    vector<long long> p_pow;
    vector<long long> hash;
public:
    void init(string text){
        int n = text.size();
        p_pow.resize(n + 1);
        hash.resize(n + 1, 0);
        p_pow[0] = 1;
        for(int i = 1; i < n; i++){
            p_pow[i] = (p_pow[i - 1] * p) % mod;
        }
        for(int i = 0; i < n; i++){
            hash[i + 1] = (hash[i] + (text[i] - 'a' + 1) * p_pow[i]) % mod;
        }
    }
    vector<long long> calculateSourceHash(vector<string>& sources){
        int index = 0, n = sources.size();
        vector<long long> shash(n + 1);
        for(auto &s : sources){
            long long hs = 0;
            for(int i = 0; i < s.size(); i++){
                hs = (hs + (s[i] - 'a' + 1) * p_pow[i]) % mod;
            }
            shash[index++] = hs;
        }
        return shash;
    }
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        init(s);
        vector<long long> shash = calculateSourceHash(sources);
        vector<pair<int, int>> nindices;
        int n = s.size(), k = indices.size(), prev = 0;
        for(int i = 0; i < k; i++){
            nindices.push_back({indices[i], i});
        }
        sort(nindices.begin(), nindices.end(), [](auto &a, auto &b){
           return a.first < b.first; 
        });
        string res;
        for(int i = 0; i < k; i++){
            int index = nindices[i].second, val = nindices[i].first;
            // for(int j = prev; j < val; j++){
            //     res += s[j];
            //     prev++;
            // }
            res += s.substr(prev, val - prev);
            prev += val - prev;
            int sLen = sources[index].size();
            long long curr_hash;
            if(val + sLen - 1 < n){
                curr_hash = (hash[val + sLen] + mod - hash[val]) % mod;
            }
            else{
                curr_hash = -1;
            }
            if(curr_hash == shash[index] * p_pow[val] % mod){
                res += targets[index];
                prev += sLen;
            }
            else{
                prev = val;
            }
            if(i == k - 1){
                // for(int j = prev; j < n; j++){
                //     res += s[j];
                // }
                res += s.substr(prev, n);
            }
        }
        return res;
    }
};