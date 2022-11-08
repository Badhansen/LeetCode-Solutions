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
    bool Dfs(TreeNode* root, long long min, long long max) {
        if (root == NULL) {
            return true;
        }
        if (min < root->val && root->val < max) {
            return Dfs(root->left, min, root->val) && Dfs(root->right, root->val, max);
        }
        return false;
    }
    bool isValidBST(TreeNode* root) {
        return Dfs(root, 1ll * INT_MIN - 1, 1ll * INT_MAX + 1);
    }
};