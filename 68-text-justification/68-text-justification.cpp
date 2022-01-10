class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> answer, res;
        vector<vector<string>> result;
        
        if(words.size() == 0) return answer;
        
        bool flag = true;
        int lsize = 0;
        
        for(int i = 0; i < words.size(); i++){
            if(flag){
                res.push_back(words[i]);
                lsize = words[i].size();
                flag = false;
            }
            else{
                if(lsize + words[i].size() + 1 <= maxWidth){
                    lsize += words[i].size() + 1;
                    res.push_back(words[i]);
                }
                else{
                    result.push_back(res);
                    lsize = 0;
                    flag = true;
                    res.clear();
                    i--;
                }
            }
        }

        result.push_back(res);
        int rsize = result.size();
        
        for(int i = 0; i < rsize - 1; i++){
            int len = 0;
            
            for(auto &r : result[i]){
                len += r.size();
            }
            
            int size = result[i].size();
            int space = maxWidth - len;
            int wordSpace = size > 1 ? space / (size - 1) : 0;
            int rem = size > 1 ? space % (size - 1) : 0;
            
            string line, sp;
            
            for(auto &l : result[i]){
                if(line.empty()){
                    line = l;
                }
                else{
                    sp = string(wordSpace, ' ');
                    if(rem){
                        sp.push_back(' ');
                        rem--;
                    }
                    line.append(sp);
                    line.append(l);
                }
            }
            
            if(line.size() < maxWidth){
                line.append(string(maxWidth - line.size(), ' '));
            }
            answer.push_back(line);
        }
        
        string line = "";
        
        for(int i = 0; i < result[rsize - 1].size(); i++){
            if(line.empty()){
                line = result[rsize - 1][i];
            }
            else{
                line.push_back(' ');
                line.append(result[rsize - 1][i]);
            }
        }
        
        if(line.size() < maxWidth){
            line.append(string(maxWidth - line.size(), ' '));
        }
        
        answer.push_back(line);
        
        return answer;
    }
};