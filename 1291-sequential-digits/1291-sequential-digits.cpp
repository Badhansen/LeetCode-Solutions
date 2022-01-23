class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string res = "123456789";
        vector<int> ans;
        int lowLen = to_string(low).size();
        int highLen = to_string(high).size();
        for(int len = lowLen; len <= highLen; len++){
            for(int st = 0; st < 10 - len; st++){
                string nRes = res.substr(st, len);
                int num = stoi(nRes);
                if(num >= low && num <= high){
                    ans.push_back(num);
                }
            }
        }
        return ans;
    }
};