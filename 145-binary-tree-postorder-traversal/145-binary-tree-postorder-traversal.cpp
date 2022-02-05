/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> path;
    void rec(TreeNode* root){
        if(root == NULL) return;
        rec(root->left);
        rec(root->right);
        path.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        rec(root);
        return path;
    }
};