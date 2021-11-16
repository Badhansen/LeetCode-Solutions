class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.size(), count = 0;
        bool flag = false;
        for(int i = len - 1; i >= 0; i--){
            if(!flag && s[i] == ' '){
                continue;
            }
            else if(flag && s[i] == ' '){
                return count;
            }
            else{
                count++;
                flag = true;
            }
        }
        
        return count;
    }
};

// Time Complxity: O(N), where N = length of the string.
// Space Complexity: O(1), Here we used only constant space.
