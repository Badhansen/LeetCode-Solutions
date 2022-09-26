class Solution {
private:
    vector<int> _parent;
    vector<int> _size;
public:
    int Find(int x) {
        if (x == _parent[x]) {
            return x;
        }
        return _parent[x] = Find(_parent[x]);
    }
    void Union(int a, int b) {
        a = Find(a);
        b = Find(b);
        if (a != b) {
            if (_size[a] < _size[b]) {
                swap(a, b);
            }
            _parent[b] = a;
            _size[a] += _size[b];
        }
    }
    bool equationsPossible(vector<string>& equations) {
        _parent.resize(26);
        _size.resize(26, 1);
        for (int i = 0; i < 26; i++) {
            _parent[i] = i;
        }
        for (auto e : equations) {
            int a = e[0] - 'a';
            int b = e[3] - 'a';
            
            if (e[1] == '=') {
                Union(a, b);
            }
        }
        for (auto e : equations) {
            int a = e[0] - 'a';
            int b = e[3] - 'a';
            if (e[1] == '!') {
                a = Find(a);
                b = Find(b);
                if (a == b) {
                    return false;
                }
            }
        }
        return true;
    }
};