class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string row[3] = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
        vector<string> ans;
        for(auto word : words){
            int index = -1;
            for(int i = 0; i < 3; i++){
                if(row[i].find(tolower(word[0])) != string::npos) index = i;
            }
            
            if(index == -1) continue;
            
            bool flag = true;
            for(int i = 1; i < word.size(); i++){
                if(row[index].find(tolower(word[i])) == string::npos){
                    flag = false;
                    break;
                }
            }
            if(flag) ans.push_back(word);
        }
        return ans;
    }
};