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
    bool go(TreeNode* root, int sum){
        if(root == NULL) return false;
        sum -= root->val;
        if(root->left == NULL && root->right == NULL)
            return (sum == 0);
        return go(root->left, sum) || go(root->right, sum);
    }

    bool hasPathSum(TreeNode* root, int sum) {
        return go(root, sum);
    }
};