// @Author: KING-SEN

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        int size = a + b + c;
        int countA = 0, countB = 0, countC = 0;
        string ans;
        for(int i = 0; i < size; i++){
            if((a >= b && a >= c && countA != 2) || (countB == 2 && a > 0) || (countC == 2 && a > 0)){
                ans.push_back('a');
                a--;
                countA++;
                countB = 0;
                countC = 0;
            }
            else if((b >= a && b >= c && countB != 2) || (countA == 2 && b > 0) || (countC == 2 && b > 0)){
                ans.push_back('b');
                b--;
                countB++;
                countA = 0;
                countC = 0;
            }
            else if((c >= a && c >= b && countC != 2) || (countA == 2 && c > 0) || (countB == 2 && c > 0)){
                ans.push_back('c');
                c--;
                countC++;
                countA = 0;
                countB = 0;
            }
        }
        return ans;
    }
};