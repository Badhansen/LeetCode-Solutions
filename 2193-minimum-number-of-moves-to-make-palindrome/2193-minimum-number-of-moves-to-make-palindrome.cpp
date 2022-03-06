class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int len = s.size();
        int ans = 0;
        for(int l = 0, r = len - 1; l < r; l++, r--){
            if(s[l] == s[r]){
                continue;
            }
            char lChar = s[l], rChar = s[r];
            int left = l, right = r;
            while(left < r && s[left] != s[r]){
                left++;
            }
            int lMove = left - l;
            while(right > l && s[right] != s[l]){
                right--;
            }
            int rMove = r - right;
            if(lMove > rMove){
                ans += rMove;
                int n = right;
                while(n < r){
                    swap(s[n], s[n + 1]);
                    n++;
                }
            }
            else{
                ans += lMove;
                int n = left;
                while(n > l){
                    swap(s[n], s[n - 1]);
                    n--;
                }
            }
        }
        return ans;
    }
};