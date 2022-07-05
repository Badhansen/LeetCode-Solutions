class Solution {
public:
    vector<int> pr, _size;
    int _find(int r){
        if(r == pr[r]) return r;
        return pr[r] = _find(pr[r]);
    }
    void _union(int a, int b){
        int x = _find(a), y = _find(b);
        if(x != y){
            if(x < y) swap(x, y);
            _size[x] += _size[y];
            pr[y] = x;
        }
    }
    int longestConsecutive(vector<int>& nums) {
        int siz = nums.size();
        if(!siz) return 0;
        pr.assign(siz, 0);
        for(int i = 0; i < siz; i++){
            pr[i] = i;
        }
        _size.assign(siz, 1);
        
        unordered_map<int, int> keep;
        for(int i = 0; i < siz; i++){
            keep[nums[i]] = i;
        }
        for(auto &el : nums){
            if(keep.find(el + 1) != keep.end()){
                _union(keep[el + 1], keep[el]);
            }
        }
        int maxCount = 1;
        for(int i = 0; i < siz; i++){
            maxCount = max(maxCount, _size[i]);
        }
        return maxCount;
    }
};