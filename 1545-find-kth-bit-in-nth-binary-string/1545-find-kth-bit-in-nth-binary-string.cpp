class Solution {
public:
    char findKthBit(int n, int k) {
        if(n == 1 && k == 1) return '0';
        int mid = (1 << (n - 1));
        if(mid == k) return '1';
        if(k < mid){
            return findKthBit(n - 1, k);
        }
        if(findKthBit(n - 1, mid * 2 - k) == '0'){
            return '1';
        }
        else{
            return '0';
        }
    }
};
