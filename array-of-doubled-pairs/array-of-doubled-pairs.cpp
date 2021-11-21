class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int, int> seen;
        
        for(auto &num : arr){
            seen[num]++;    
        }
        
        vector<int> keys;
        
        for(auto &[key, value] : seen){
            keys.push_back(key);
        }
        
        sort(keys.begin(), keys.end(),[](int a, int b){
            return abs(a) < abs(b);
        });
        
        for(auto &key : keys){
            if(seen[key] > seen[key * 2])
                return false;
            seen[key * 2] -= seen[key];
        }
        
        return true;
    }
};