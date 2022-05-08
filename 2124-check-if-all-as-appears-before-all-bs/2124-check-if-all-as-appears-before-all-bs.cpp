class Solution {
public:
    bool checkString(string s) {
        bool bflag = false;
        for(auto c : s){
            if(c == 'b'){
                bflag = true;
            }
            else if(c == 'a' && bflag){
                return false;
            }
        }
        return true;
    }
};