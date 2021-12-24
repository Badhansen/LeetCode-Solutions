class Solution {
public:
    string reverseWords(string s) {
        vector<string> res;
        stringstream ss(s);
        string word;
        string ans;
        while(ss >> word){
            res.push_back(word);
        }
        for(int i = res.size() - 1; i >= 0; i--){
            if(i == 0)
                ans.append(res[i]);
            else{
                ans.append(res[i]);
                ans.append(" ");
            }
        }
        return ans;
    }
};