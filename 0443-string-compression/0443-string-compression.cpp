class Solution {
public:
    int compress(vector<char>& chars) {
        int count = 1;
        string ans = "";
        for (int i = 1; i < chars.size(); i++) {
            if (chars[i - 1] == chars[i]) {
                count++;
            } else {
                ans.push_back(chars[i - 1]);
                if (count > 1) {
                    ans += to_string(count);
                }
                count = 1;
            }
        }
        ans.push_back(chars[chars.size() - 1]);
        if (count > 1) {
            ans += to_string(count);
        }
        for (int i = 0; i < ans.size(); i++) {
            chars[i] = ans[i];
        }
        return ans.size();
    }
};