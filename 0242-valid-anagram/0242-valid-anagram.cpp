class Solution {
public:
    bool isAnagram(string s, string t) {
        int arr[26] = {0};
        for(int i = 0; s[i]; i++){
            arr[s[i] - 'a']++;
        }
        for(int i = 0; t[i]; i++){
            arr[t[i] - 'a']--;
        }
        for(int i = 0; i < 26; i++){
            if(arr[i] != 0) return 0;
        }
        return 1;
    }
};