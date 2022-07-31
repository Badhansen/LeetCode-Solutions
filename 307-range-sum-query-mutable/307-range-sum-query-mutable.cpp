#define MAXN 100005
struct SegTree{
    int n, t[4 * MAXN];
    void init(int _n){
        n = _n;
    }
    void build(vector<int> &a, int v, int tl, int tr){
        if(tl == tr){
            t[v] = a[tl];
        }
        else{
            int tm = (tl + tr) / 2;
            build(a, v * 2, tl, tm);
            build(a, v * 2 + 1, tm + 1, tr);
            t[v] = t[v * 2] + t[v * 2 + 1];
        }
    }
    void build(vector<int> &a){
        build(a, 1, 0, n - 1);
    }
    void set(int v, int idx, int val, int tl, int tr){
        if(tl == tr){
            t[v] = val;
        }
        else{
            int tm = (tl + tr) / 2;
            if(idx <= tm){
                set(v * 2, idx, val, tl, tm);
            }
            else{
                set(v * 2 + 1, idx, val, tm + 1, tr);
            }
            t[v] = t[v * 2] + t[v * 2 + 1];
        }
    }
    void set(int idx, int val){
        set(1, idx, val, 0, n - 1);
    }
    int get(int v, int l, int r, int tl, int tr){
        if(l > r) return 0;
        if(l == tl && r == tr){
            return t[v];
        }
        int tm = (tl + tr) / 2;
        int left = get(v * 2, l, min(tm, r), tl, tm);
        int right = get(v * 2 + 1, max(l, tm + 1), r, tm + 1, tr);
        return left + right;
    }
    int get(int l, int r){
        return get(1, l, r, 0, n - 1);
    }
};

class NumArray {
public:
    SegTree st;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        st.init(n);
        st.build(nums);
    }
    
    void update(int index, int val) {
        st.set(index, val);
    }
    
    int sumRange(int left, int right) {
        return st.get(left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */