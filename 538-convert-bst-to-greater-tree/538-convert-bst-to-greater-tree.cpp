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
    void rec(TreeNode* root, int &sum){
        if(root == NULL){
            return;
        }
        if(root->right){
            rec(root->right, sum);
        }
        sum += root->val;
        root->val = sum;
        if(root->left){
            rec(root->left, sum);
        }
    }
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        rec(root, sum);
        return root;
    }
};