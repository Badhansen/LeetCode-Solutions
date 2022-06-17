class Solution {
public:
    int getLessEqual(vector<vector<int>>& matrix, int val){
        int n = matrix.size(), r = n - 1, c = 0;
        int res = 0;
        while(r >= 0 && c < n){
            if(matrix[r][c] > val) r--;
            else{
                res += r + 1;
                c++;
            }
        }
        return res;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0], high = matrix[n - 1][n - 1];
        int answer;
        while(low <= high){
            int mid = (high - low) / 2 + low;
            int count = getLessEqual(matrix, mid);
            if(count < k){
                low = mid + 1;
            }
            else{
                answer = mid;
                high = mid - 1;
            }
        }
        return answer;
    }
    
};
