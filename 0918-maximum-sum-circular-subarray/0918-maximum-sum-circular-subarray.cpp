class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        if(A.size() == 0) return 0;
        int max_in_total = A[0];
        int min_in_total = A[0];
        int max_till_here = A[0];
        int min_till_here = A[0];
        int sum = A[0];
        for(int i = 1; i < A.size(); i++){
            if(max_till_here + A[i] > A[i]){
                max_till_here += A[i];
            }
            else{
                max_till_here = A[i];
            }
            
            max_in_total = max(max_in_total, max_till_here);
            
            if(min_till_here + A[i] < A[i]){
                min_till_here += A[i];
            }
            else{
                min_till_here = A[i];
            }
            
            min_in_total = min(min_in_total, min_till_here);
            sum += A[i];
        }
        if(sum == min_in_total) 
            return max_in_total;
        else 
            return max(max_in_total, sum - min_in_total);
        
    }
};