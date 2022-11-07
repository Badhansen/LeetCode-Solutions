class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        vector<string> res;
        for(int i = 0; i < n; i++){
            int j = i, totlen = 0;
            vector<string> vec;
            while(j < n && totlen + vec.size() + words[j].size() <= maxWidth){
                vec.push_back(words[j]);
                totlen += words[j].size();
                j++;
            }
            i = j - 1;
            res.push_back(process(vec, maxWidth, j == n));
        }
        return res;
    }
    
    string process(vector<string> &vec, int maxWidth, int lastLine){
        int sz = vec.size();
        string ret = "";
        if(sz == 1){
            ret = vec[0];
            while(ret.size() < maxWidth) ret += " ";
        }
        else if(lastLine){
            ret = vec[0];
            for(int i = 1; i < sz; i++) ret += " " + vec[i];
            while(ret.size() < maxWidth) ret += " ";
        }
        else {
            int totlen = 0;
            for(int i = 0; i < sz; i++) totlen += vec[i].size();
            int rem = maxWidth - totlen;
            int c = rem / (sz - 1), d = rem % (sz - 1);
            ret = vec[0];
            for(int i = 1; i < sz; i++){
                for(int j = 0; j < c; j++) ret += " ";
                if(d > 0){
                    ret += " ";
                    d--;
                }
                ret += vec[i];
            }
        }
        return ret;
    }
};