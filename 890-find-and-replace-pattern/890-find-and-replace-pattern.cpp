class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for(auto el : words){
            map<char, char> pb, wb;
            bool flag = true;
            for(int i = 0; i < pattern.size(); i++){
                if(pb.count(pattern[i]) || wb.count(el[i])){
                    if(pb[pattern[i]] != el[i]){
                        flag = false;
                        break;
                    }
                }
                else{
                    pb[pattern[i]] = el[i];
                    wb[el[i]] = pattern[i];
                }
            }
            if(flag){
                ans.push_back(el);
            }
        }
        return ans;
    }
};