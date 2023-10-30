class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> v[32];
        for(int i = 0; i < arr.size(); i++){
            int x = __builtin_popcount(arr[i]);
            v[x].push_back(arr[i]);
        }
        arr.clear();
        for(int i = 0; i < 32; i++){
            sort(v[i].begin(), v[i].end());
            for(auto x : v[i]){
                arr.push_back(x);
            }
        }
        return arr;
    }
};