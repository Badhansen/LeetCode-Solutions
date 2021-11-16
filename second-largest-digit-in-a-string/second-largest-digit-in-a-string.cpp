class Solution {
public:
    int secondHighest(string s) {
        int fMax = -1, sMax = -1;
        
        for(int i = 0; i < s.size(); i++){
            if(isdigit(s[i])){
                int digit = s[i] - '0';
                if(fMax == -1){
                    fMax = digit;
                }
                else if(digit > fMax){
                    sMax = fMax;
                    fMax = digit;
                }
                else if(digit > sMax && digit < fMax){
                    sMax = digit;
                }
            }
        }
        
        return sMax;
    }
};

// Time Complexity: O(N), Here N = Length of the string.
// Space Complexity: O(1), Here we use only constant space.