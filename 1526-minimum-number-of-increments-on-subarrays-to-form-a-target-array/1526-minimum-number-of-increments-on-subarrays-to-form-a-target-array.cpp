struct Node{
    int index;
    int val;
    Node(){}
    Node(int i, int v){
        index = i;
        val = v;
    }
};
class SegTree{
private:
    vector<Node> tree;
    vector<int> nums;
public:
    SegTree(){}
    SegTree(int n, vector<int>& val){
        tree.resize(4 * n);
        nums = val;
        build_tree(0, 0, n - 1);
    }
    Node merge(Node& a, Node& b){
        if(a.val == b.val){
            return a.index < b.index ? a : b;
        }
        return a.val < b.val ? a : b;
    }
    void build_tree(int node, int slow, int shigh){
        if(slow == shigh){
            tree[node] = Node(slow, nums[slow]);
            return;
        }
        
        int left = 2 * node + 1;
        int right = 2 * node + 2;
        int mid = (slow + shigh) / 2;
        
        build_tree(left, slow, mid);
        build_tree(right, mid + 1, shigh);
        
        tree[node] = merge(tree[left], tree[right]);
    }
    
    Node query(int node, int slow, int shigh, int i, int j){
        if(i > shigh || j < slow || slow > shigh)
            return Node(-1, INT_MAX);
        if (slow >= i && shigh <= j)
            return tree[node];
        
        int left = 2 * node + 1;
        int right = 2 * node + 2;
        int mid = (slow + shigh) / 2;
        
        Node lmin = query(left, slow, mid, i, j);
        Node rmin = query(right, mid + 1, shigh, i, j);
        
        return merge(lmin, rmin);
    }
};

class Solution {
private:
    SegTree *mintree;
    int n;
public:
    void init(int n, vector<int>& val){
        mintree = new SegTree(n, val);
        this->n = n;
    }
    int divide(int st, int ed, int operations){
        if(st > ed) return 0;
        Node m = mintree->query(0, 0, n - 1, st, ed);
        
        int op = m.val - operations;
        int left = divide(st, m.index - 1, m.val);
        int right = divide(m.index + 1, ed, m.val);
        
        return op + left + right;
    }
    int minNumberOperations(vector<int>& target) {
        n = target.size();
        init(n, target);
        return divide(0, n - 1, 0);
    }
};
