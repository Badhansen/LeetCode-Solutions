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
    bool dfs(TreeNode* firstTree, TreeNode* secondTree){
        if(firstTree == NULL && secondTree == NULL)
            return true;
        if(firstTree == NULL || secondTree == NULL)
            return false;
        if(firstTree->val == secondTree->val){
            return dfs(firstTree->left, secondTree->right) &&
                dfs(firstTree->right, secondTree->left);
        }
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        
        return dfs(root, root);
    }
};