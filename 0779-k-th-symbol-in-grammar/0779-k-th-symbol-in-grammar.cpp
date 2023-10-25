class Solution {
public:
    int solve(int k){
        if(k == 1) return 0;
        if(k == 2) return 1;
        
        int ret = solve((k + 1) / 2);
        
        if(ret == 0){
            if(k & 1) return 0;
            return 1;
        }
        else{
            if(k & 1) return 1;
            return 0;
        }
    }
    int kthGrammar(int n, int k) {
        return solve(k);
    }
};
/*
1 = 0
2 = 01
3 = 0110
4 = 01101001
5 = 0110100110010110
*/