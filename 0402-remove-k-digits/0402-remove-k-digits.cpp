class Solution {
public:
    string removeKdigits(string num, int k) {
        string result;
        for (int i = 0; i < num.size(); i++) {
            while (!result.empty() && k && result.back() > num[i]) {
                k--;
                result.pop_back();
            }
            if (num[i] == '0') {
                if (!result.empty()) {
                    result.push_back(num[i]);
                }
            } else {
                result.push_back(num[i]);
            }
        }
        while(k and !result.empty()) {
            k--;
            result.pop_back();
        }
        return result.empty() ? "0" : result;
    }
};