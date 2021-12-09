class Solution {
public:
    bool rec(vector<int> &v, int pos){
        if(pos < 0 || pos >= v.size()) 
            return false;
        if(v[pos] == 0) 
            return true;
        int jump = v[pos];
        if(jump > v.size()) 
            return false;
        
        v[pos] += 1e8;
        
        return rec(v, pos + jump) | rec(v, pos - jump);
    }
    bool canReach(vector<int>& arr, int start) {
        return rec(arr, start);
    }
};