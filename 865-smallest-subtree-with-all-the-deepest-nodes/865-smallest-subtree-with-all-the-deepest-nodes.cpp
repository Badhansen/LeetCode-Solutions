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
private:
    TreeNode* lca = NULL;
    int deepest = 0;
public:
    int dfs(TreeNode* root, int deep){
        deepest = max(deepest, deep);
        if(root == NULL){
            return deep;
        }
        int left = dfs(root->left, deep + 1);
        int right = dfs(root->right, deep + 1);
        if(left == deepest && right == deepest){
            lca = root;
        }
        return max(left, right);
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        dfs(root, 0);
        return lca;
    }
};