class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> seen;
        int len1 = list1.size(), len2 = list2.size();
        vector<string> ans;
        int sum = INT_MAX;
        for(int i = 0; i < len1; i++){
            seen[list1[i]] = i;
        }
        for(int i = 0; i < len2; i++){
            if(seen.count(list2[i])){
                int indexSum = seen[list2[i]] + i;
                if(sum == indexSum){
                    ans.push_back(list2[i]);
                }
                else if(sum > indexSum){
                    sum = indexSum;
                    ans.clear();
                    ans.push_back(list2[i]);
                }
            }    
        }
        return ans;
    }
};
//list1 = ["Shogun","Tapioca Express","Burger King","KFC"], 
//list2 = ["KFC","Shogun","Burger King"]