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
        path.push_back(root->val);
        rec(root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        rec(root);
        return path;
    }
};