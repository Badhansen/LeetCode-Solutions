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
public:
    Node* NodeConnect(Node* root){
        if(!root)
            return root;
        if(root->left){
            root->left->next = root->right;
        }
        if(root->next && root->right){
            root->right->next = root->next->left;
        }
        root->left = NodeConnect(root->left);
        root->right = NodeConnect(root->right);
        return root;
    }
    Node* connect(Node* root) {
        return NodeConnect(root);
    }
};