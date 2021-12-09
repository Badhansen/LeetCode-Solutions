class Solution {
public:
    bool rec(vector<int> &arr, int pos){
        if(pos < 0 || pos >= arr.size()) 
            return false;
        
        if(arr[pos] == 0) 
            return true;
        
        int jump = arr[pos];
        
        if(jump > arr.size()) 
            return false;
        
        arr[pos] += 1e8;
        
        return rec(arr, pos + jump) | rec(arr, pos - jump);
    }
    bool canReach(vector<int>& arr, int start) {
        return rec(arr, start);
    }
};