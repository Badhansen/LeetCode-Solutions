class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<int> cnt(26, 0);
        for(auto &bl : B){
            vector<int> tmpCnt(26, 0);
            for(auto &ch : bl) tmpCnt[ch - 'a']++;
            for(int i = 0; i < 26; i++){
                cnt[i] = max(cnt[i], tmpCnt[i]);
            }
        }
        vector<string> ans;
        for(auto &al : A){
            vector<int> tmpCnt(26, 0);
            for(auto &ch : al) tmpCnt[ch - 'a']++;
            bool flag = true;
            for(int i = 0; i < 26; i++){
                if(tmpCnt[i] >= cnt[i]) continue;
                else{
                    flag = false;
                    break;
                }
            }
            if(flag) ans.push_back(al);
        }
        return ans;
    }
};