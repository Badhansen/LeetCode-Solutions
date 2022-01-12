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
    int solve(TreeNode* root, int parent, int gParent){
        if(!root) return 0;
        return solve(root->left, !(root->val & 1), parent) +
            solve(root->right, !(root->val & 1), parent) + (gParent & 1 ? root->val : 0);
    }
    int sumEvenGrandparent(TreeNode* root) {
        return solve(root, 0, 0);
    }
};