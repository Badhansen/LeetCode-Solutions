class Solution {
public:
    bool isValid(int a, int b, int c){
        if(a > c - b && b > a - c && c > b - a) return true;
        return false;
    }
    int largestPerimeter(vector<int>& A) {
        sort(A.begin(), A.end());
        int ans = 0;
        for(int i = 0; i < A.size() - 2; i++){
            if(isValid(A[i], A[i + 1], A[i + 2])){
                ans = max(ans, A[i] + A[i + 1] + A[i + 2]);
            }
        }
        return ans;
    }
};