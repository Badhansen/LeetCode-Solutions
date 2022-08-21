class SegTree {
private:
    int size;
    vector<long long> tree;
public:
    SegTree(int n) {
        size = 1;
        while (size < n) {
            size *= 2;
        }
        tree.resize(2 * size, 0);
    }
    void build(vector<int> &v, int n, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < n) {
                tree[x] = v[lx];
            }
            return;
        }
        int m = (lx + rx) / 2;
        build(v, n, 2 * x + 1, lx, m);
        build(v, n, 2 * x + 2, m, rx);
        tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
    }
    void build(vector<int> &v, int n) {
        build(v, n, 0, 0, size);
    }
    void updateRange(int l, int r, int val, int x, int lx, int rx) {
        if (lx >= r || l >= rx) return;
        if (lx >= l && rx <= r) {
            tree[x] += val;
            return;
        }
        int m = (lx + rx) / 2;
        updateRange(l, r, val, 2 * x + 1, lx, m);
        updateRange(l, r, val, 2 * x + 2, m, rx);
    }
    void updateRange(int l, int r, int val) {
        updateRange(l, r, val, 0, 0, size);
    }
    long long get(int i, int x, int lx, int rx) {
        if (rx - lx == 1) {
            return tree[x];
        }
        int m = (lx + rx) / 2;
        long long res;
        if (i < m) {
            res = get(i, 2 * x + 1, lx, m);
        }
        else{
            res = get(i, 2 * x + 2, m, rx);
        }
        return res + tree[x];
    }
    long long get(int i) {
        return get(i, 0, 0, size);
    }
    ~SegTree() {
        tree.clear();
    }
};

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        SegTree root(n);
        for (auto st : shifts) {
            if (st[2] == 1) {
                root.updateRange(st[0], st[1] + 1, 1);
            } else {
                root.updateRange(st[0], st[1] + 1, -1);
            }
        }
        for (int i = 0; i < n; i++) {
            int val = root.get(i) % 26;
            if (val < 0) val += 26;
            val += (s[i] - 'a');
            val %= 26;
            s[i] = 'a' + val;
        }
        return s;
    }
};