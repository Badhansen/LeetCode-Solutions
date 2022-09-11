class SegTree {
private:
    int size = 1;
    vector<int> tree;
public:
    SegTree(int n) {
        size = 1;
        while (size < n) {
            size *= 2;
        }
        tree.resize(2 * size, 0);
    }
    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            tree[x] = max(tree[x], v);
            return;
        }
        int m = (lx + rx) / 2;
        if (i < m) {
            set(i, v, 2 * x + 1, lx, m);
        }
        else{
            set(i, v, 2 * x + 2, m, rx);
        }
        tree[x] = max(tree[2 * x + 1], tree[2 * x + 2]);
    }
    void set(int i, int v) { // set i'th value
        set(i, v, 0, 0, size);
    }
    int get(int l, int r, int x, int lx, int rx) {
        if (lx >= r || l >= rx) {
            return 0;
        }
        if (lx >= l && rx <= r) {
            return tree[x];
        }
        int m = (lx + rx) / 2;
        int left = get(l, r, 2 * x + 1, lx, m);
        int right = get(l, r, 2 * x + 2, m, rx);
        return max(left, right);
    }
    int get(int l, int r) { // return [l, r) range value
        return get(l, r, 0, 0, size);
    }
    ~SegTree() {
        tree.clear();
    }
};

class Solution {
private:
    const int kINF = 1e9, kMax = 1e5;
public:
    int lengthOfLIS(vector<int>& nums, int k) {
        int n = nums.size();
        SegTree max_tree(kMax + 1);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int left = max(0, nums[i] - k);
            int curr = max_tree.get(left, nums[i]) + 1; // as this segment tree work's [l, r) so nums[i] - 1 is not necessary
            max_tree.set(nums[i], curr);
            ans = max(ans, curr);
        }
        return ans;
    }
};