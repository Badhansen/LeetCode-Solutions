class Solution {
private:
    const int p = 31;
    const int mod = 1e9 + 7;
    vector<long long> p_pow;
    vector<long long> hash;
public:
    // Rabin-Karp Algorithm for string matching
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
    // Calculate the pattern string hash
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
        init(s); // O(N)
        vector<long long> shash = calculateSourceHash(sources); // O(K * L)
        vector<pair<int, int>> nindices;
        string res;
        int n = s.size(), k = indices.size(), prev = 0;
        
        for(int i = 0; i < k; i++){
            nindices.push_back({indices[i], i});
        }
        
        // Sort the with respect to index value with O(K log K)
        sort(nindices.begin(), nindices.end(), [](auto &a, auto &b){
           return a.first < b.first; 
        });
        
        for(int i = 0; i < k; i++){ // O(K)
            int index = nindices[i].second, val = nindices[i].first;
            
            res += s.substr(prev, val - prev); // Adding the substring up to the current indices with O(Length) time 
            prev += val - prev; // Updating the previous index for substring addition
            
            int sLen = sources[index].size();
            long long curr_hash;
            
            if(val + sLen - 1 < n){
                curr_hash = (hash[val + sLen] + mod - hash[val]) % mod; // Calculating the substring hash with O(1) time
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
                res += s.substr(prev, n); // Have to add all the remaing character with O(Length) time
            }
        }
        return res;
    }
};