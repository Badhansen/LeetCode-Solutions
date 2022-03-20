class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        int rotationA = 0, rotationB = 0;
        for(int i = 0; i < n && (tops[i] == tops[0] || bottoms[i] == tops[0]); i++){
            if(tops[i] != tops[0]){
                rotationA++;
            }
            if(bottoms[i] != tops[0]){
                rotationB++;
            }
            if(i == n - 1){
                return min(rotationA, rotationB);
            }
        }
        rotationA = 0, rotationB = 0;
        for(int i = 0; i < n && (tops[i] == bottoms[0] || bottoms[i] == bottoms[0]); i++){
            if(bottoms[i] != bottoms[0]){
                rotationA++;
            }
            if(tops[i] != bottoms[0]){
                rotationB++;
            }
            if(i == n - 1){
                return min(rotationA, rotationB);
            }
        }
        return -1;
    }
};