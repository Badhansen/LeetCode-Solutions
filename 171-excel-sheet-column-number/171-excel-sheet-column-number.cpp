class Solution {
public:
    
    int titleToNumber(string columnTitle) {
        reverse(columnTitle.begin(), columnTitle.end());
        int result = 0;
        long curr = 1;
        for(int i = 0; i < columnTitle.size(); i++){
            int num = (columnTitle[i] - 'A') + 1;
            result += curr * num;
            curr *= 26;
        }
        return result;
    }
};