class Solution {
private:
    vector<vector<int>> cache;
public:
    bool dfs(int l1, int l2, string& s1, string& s2, string& s3){
        if(l1 == s1.size() && l2 == s2.size()){
            return 1;
        }
        int &ret = cache[l1][l2];
        if(ret != -1){
            return ret;
        }
        if(l1 < s1.size() && s1[l1] == s3[l1 + l2] && dfs(l1 + 1, l2, s1, s2, s3)){
            return 1;
        }
        if(l2 < s2.size() && s2[l2] == s3[l1 + l2] && dfs(l1, l2 + 1, s1, s2, s3)){
            return 1;
        } 
        return ret = 0;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.size(), len2 = s2.size(), len3 = s3.size();
        if(len1 + len2 != len3){
            return false;
        }
        cache.resize(len1 + 1, vector<int>(len2 + 2, -1));
        if(dfs(0, 0, s1, s2, s3)){
            return true;
        }
        return false;
    }
};