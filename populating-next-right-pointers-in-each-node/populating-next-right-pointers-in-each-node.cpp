/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
private:
    vector<vector<Node*>> view;    
public:
    void solve(Node* root, int level){
        if(root == NULL)
            return;
        if(level == view.size())
            view.push_back({});
        view[level].push_back(root);
        solve(root->left, level + 1);
        solve(root->right, level + 1);
    }
    Node* connect(Node* root) {
        solve(root, 0);
        int len = view.size();
        for(int i = 0; i < len; i++){
            for(int j = 1; j < view[i].size(); j++){
                view[i][j - 1]->next = view[i][j];
            }
        }
        return root;
    }
};