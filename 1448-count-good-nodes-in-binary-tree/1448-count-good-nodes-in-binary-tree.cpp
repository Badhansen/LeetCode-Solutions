/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int dfs(TreeNode* root, int max_val) {
        if (root == NULL) return 0;
        max_val = max(max_val, root->val);
        if (root->val >= max_val) {
            return 1 + dfs(root->left, max_val) + dfs(root->right, max_val);
        }
        return dfs(root->left, max_val) + dfs(root->right, max_val);
    }
    int goodNodes(TreeNode* root) {
        return dfs(root, INT_MIN);
    }
};