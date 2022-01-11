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
    int rec(TreeNode* root, int ans)
    {
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL) return (ans << 1) + root->val;
        ans = (ans << 1) + root->val;
        return rec(root->left, ans) + rec(root->right, ans);
    }
    int sumRootToLeaf(TreeNode* root) {
        int ans = 0;
        return rec(root, ans);
    }
};