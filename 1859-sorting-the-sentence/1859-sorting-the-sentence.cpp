class Solution {
public:
    string sortSentence(string s) {
        int count = 0;
        string words[10], ans, w;
        stringstream ss;
        ss << s;
        while(ss >> w){
            int id = w.back() - '0';
            words[id] = w.substr(0, w.size() - 1);
            count++;
        }
        for(int i = 0; i < count; i++){
            ans.append(words[i + 1]);
            if(i < count - 1){
                ans.push_back(' ');
            }
        }
        return ans;
    }
};