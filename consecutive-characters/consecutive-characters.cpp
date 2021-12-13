class Solution {
public:
    int maxPower(string s) {
        int mx = 1;
        for(int i = 0; i < s.size(); i++){
            char c = s[i];
            int j = i + 1;
            int cnt = 1;
            while(c == s[j] && j < s.size()){
                cnt++;
                i = j;
                j++;
                mx = max(mx, cnt);
            }
        }
        return mx;
    }
};