// 1 last try

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size(), res = 0;
        
        for(int j = 0; j < n; j++){
            int smallerLeft = 0, smallerRight = 0;
            int biggerLeft = 0, biggerRight = 0;
            
            for(int i = j - 1; i >= 0; i--){
                if(rating[i] < rating[j]) smallerLeft++;
                else if(rating[i] > rating[j]) biggerLeft++;
            }
            
            for(int k = j + 1; k < n; k++){
                if(rating[k] > rating[j]) biggerRight++;
                else if(rating[k] < rating[j]) smallerRight++;
            }
            
            res += smallerLeft * biggerRight + biggerLeft * smallerRight;
        }
        
        return res;
    }
};

// Time: O(N^2)
// Space: O(1)