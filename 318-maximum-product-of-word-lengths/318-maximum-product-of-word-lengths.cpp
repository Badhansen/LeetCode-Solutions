class Solution {
public:
    bool IsExist(int *arr, int *brr){
        for(int i = 0; i < 26; i++){
            if((arr[i] == 0 && brr[i] > 0) || (arr[i] > 0 && brr[i] == 0) || (arr[i] == 0 &&  brr[i] == 0)){
                continue;
            }
            return false;
        }
        return true;
    }
    int maxProduct(vector<string>& words) {
        int nCount = words.size();
        int table[nCount + 1][26];
        memset(table, 0, sizeof(table));
        
        for(int i = 0; i < nCount; i++){
            for(auto el : words[i]){
                table[i][el - 'a']++;
            }
        }
        int ans = 0;
        for(int i = 0; i < nCount; i++){
            for(int j = i + 1; j < nCount; j++){
                if(IsExist(table[i], table[j])){
                    int tempAns = words[i].size() * words[j].size();
                    ans = max(ans, tempAns);
                }
            }
        }
        return ans;
    }
};