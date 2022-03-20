class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        vector<int> countA(7), countB(7), same(7);
        int n = tops.size();
        for(int i = 0; i < n; i++){
            countA[tops[i]]++;
            countB[bottoms[i]]++;
            if(tops[i] == bottoms[i]){
                same[tops[i]]++;
            }
        }
        for(int i = 1; i < 7; i++){
            if (countA[i] + countB[i] - same[i] == n){
                return n - max(countA[i], countB[i]);
            }
        }
        return -1;
    }
};