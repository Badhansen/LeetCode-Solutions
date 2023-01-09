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
        path.push_back(root->val);
        rec(root->left);
        rec(root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        rec(root);
        return path;
    }
};