class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        vector<vector<string>> result;
        int start, ptr = 0, n = products.size();
        string prefix;
        for(char c : searchWord){
            prefix += c;
            start = lower_bound(products.begin() + ptr, products.end(), prefix) - products.begin();
            result.push_back({});
            for(int i = start; i < min(start + 3, n); i++){
                string word = products[i].substr(0, prefix.size());
                if(word == prefix) result.back().push_back(products[i]);
                else break;
            }
            ptr = start;
        }
        return result;
    }
};