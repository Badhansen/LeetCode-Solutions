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
// @Author: KING-SEN

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root == NULL) return 0;
        int ret = root->val;
        if(ret >= low && ret <= high){
            return ret + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
        }
        else{
            return rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
        }
    }
};