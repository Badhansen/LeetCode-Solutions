class Solution {
public:
    vector<string> result;
    bool isValid(string& s){
        if(s.empty()){
            return false;
        }
        if(s.size() == 1){
            return true;
        }
        if(s[0] == '0'){
            return false;
        }
        int num = stoi(s);
        return num >= 0 && num <= 255;
    }
    void backtrack(int pos, int part, string ip, string& s){
        // base case
        if(pos == s.size()){
            if(part == 0){
                result.push_back(ip.substr(1));
            }
            return;
        }
        if(part == 0){
            return;
        }
        string tempIp = "";
        for(int i = pos; i < s.size(); i++){
            tempIp.push_back(s[i]);
            if(isValid(tempIp)){
                backtrack(i + 1, part - 1, ip + "." + tempIp, s);
            }
            else{
                break;
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        if(s.size() > 12){
            return result;
        }
        backtrack(0, 4, "", s);
        return result;
    }
};