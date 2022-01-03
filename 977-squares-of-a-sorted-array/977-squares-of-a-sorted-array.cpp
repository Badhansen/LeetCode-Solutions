class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int n = A.size();
        vector<int> vt(n);
        for(int i = 0; i < n; i++){
            vt[i] = A[i] * A[i];
        }
        sort(vt.begin(), vt.end());
        return vt;
    }
};