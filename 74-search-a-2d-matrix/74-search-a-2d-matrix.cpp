class Solution {
public:
    bool found(vector<int> &arr, int lo, int hi, int ter){
        while(hi >= lo){
            int mid = (lo + hi) / 2;
            if(arr[mid] == ter) return true;
            else if(arr[mid] < ter) lo = mid + 1;
            else hi = mid - 1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i = 0; i < matrix.size(); i++){
            if(found(matrix[i], 0, matrix[i].size() - 1, target)){
                return true;
            }
        }
        return false;
    }
};