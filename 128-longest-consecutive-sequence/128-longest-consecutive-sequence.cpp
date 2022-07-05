class UnionFind{
private:
    vector<int> parent;
    vector<int> size;
public:
    UnionFind(int n){
        parent.resize(n);
        size.resize(n, 1);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
    }
    int FindRoot(int r){
        if(parent[r] == r)
            return r;
        return parent[r] = FindRoot(parent[r]);
    }
    void Union(int a, int b){
        a = FindRoot(a);
        b = FindRoot(b);
        if(a != b){
            if(a < b) swap(a, b);
            size[a] += size[b];
            parent[b] = a;
        }
    }
    int getSize(int index){
        return size[index];
    }
    int getParent(int index){
        return parent[index];
    }
};
class Solution {
private:
    UnionFind* root;
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(!n) return 0;
        root = new UnionFind(n);
        unordered_map<int, int> keep;
        for(int index = 0; index < n; index++){
            keep[nums[index]] = index;
        }
        for(auto &num : nums){
            if(keep.find(num + 1) != keep.end()){
                root->Union(keep[num + 1], keep[num]);
            }
        }
        int maxCount = 1;
        for(int i = 0; i < n; i++){
            maxCount = max(maxCount, root->getSize(i));
        }
        return maxCount;
    }
};