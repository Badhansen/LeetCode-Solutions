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
    TreeNode* first, *second, *current;
public:
    void dfs(TreeNode* root){
        if(root == NULL){
            return;
        }
        dfs(root->left);
        if(root->val < current->val){
            if(first == NULL){
                first = current;
            }
            second = root;
        }
        current = root;
        dfs(root->right);
    }
    void recoverTree(TreeNode* root) {
        current = new TreeNode(INT_MIN);
        first = second = NULL;
        dfs(root);
        swap(first->val, second->val);
    }
};