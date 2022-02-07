class Solution {
public:
    char findTheDifference(string s, string t) {
        int x = 0;
        for(char c : s){
            x ^= c;
        }
        for(char c : t){
            x ^= c;
        }
        return x;
    }
};