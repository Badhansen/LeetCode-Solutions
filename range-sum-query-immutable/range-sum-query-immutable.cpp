class SegTree{
public:    
    int _size;
    vector<int> arr;
    SegTree(){
        _size = 1;
    }
    void init(int n){
        _size = 1;
        while(_size < n){
            _size *= 2;
        }
        arr.assign(2 * _size, 0);
    }
    void build(vector<int> &v, int x, int lx, int rx){
        if(rx - lx == 1){
            if(lx < (int) v.size()){
                arr[x] = v[lx];
            }
            return;
        }
        int m = (lx + rx) / 2;
        build(v, 2 * x + 1, lx, m);
        build(v, 2 * x + 2, m, rx);
        arr[x] = arr[2 * x + 1] + arr[2 * x + 2];
    }
    void build(vector<int> &v){
        build(v, 0, 0, _size);
    }
    void set(int i, int v, int x, int lx, int rx){
        if(rx - lx == 1){
            arr[x] = v;
            return;
        }
        int m = (lx + rx) / 2;
        if(i < m){
            set(i, v, 2 * x + 1, lx, m);
        }
        else{
            set(i, v, 2 * x + 2, m, rx);
        }
        arr[x] = arr[2 * x + 1] + arr[2 * x + 2];
    }
    void set(int i, int v){
        set(i, v, 0, 0, _size);
    }
    int get(int l, int r, int x, int lx, int rx){
        if(lx >= r || l >= rx){
            return 0;
        }
        if(lx >= l && rx <= r){
            return arr[x];
        }
        int m = (lx + rx) / 2;
        int left = get(l, r, 2 * x + 1, lx, m);
        int right = get(l, r, 2 * x + 2, m, rx);
        return left + right;
    }
    int get(int l, int r){
        return get(l, r, 0, 0, _size);
    }
    ~SegTree(){
        arr.clear();
    }
};
class NumArray {
public:
    SegTree mt;
    NumArray(vector<int>& nums) {
        mt.init(nums.size());
        mt.build(nums);
    }
    
    int sumRange(int left, int right) {
        return mt.get(left, right + 1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */