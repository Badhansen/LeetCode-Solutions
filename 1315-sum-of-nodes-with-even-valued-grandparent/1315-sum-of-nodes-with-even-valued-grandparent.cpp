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
    void solve(TreeNode* root, int parent, int gParent, int& ans){
        if(!root) return;
        if(gParent) ans += root->val;
        solve(root->left, !(root->val & 1), parent, ans);
        solve(root->right, !(root->val & 1), parent, ans);
    }
    int sumEvenGrandparent(TreeNode* root) {
        int ans = 0;
        solve(root, 0, 0, ans);
        return ans;
    }
};