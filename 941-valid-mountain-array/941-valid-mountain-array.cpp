class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int n = A.size();
        int pos = 0, mx = -1;
        for(int i= 0; i < n; i++){
            if(A[i] > mx){
                mx = A[i];
                pos = i;
            }
        }
        if(pos == 0 || n < 3 || pos == n - 1){
            return false;
        }
        int t = mx;
        for(int i = pos + 1; i < n; i++){
            if(A[i] < t){
                t = A[i];
            }
            else return false;
        }
        t = mx;
        for(int i = pos - 1; i >= 0; i--){
            if(A[i] < t){
                t = A[i];
            }
            else return false;
        }
        return true;
    }
};