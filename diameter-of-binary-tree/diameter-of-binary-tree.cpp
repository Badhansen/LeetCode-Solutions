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
    int ans;
public:
    int maxHeight(TreeNode* root){
        if(root == NULL)
            return 0;
        int left = maxHeight(root->left);
        int right = maxHeight(root->right);
        ans = max(ans, left + right);
        return max(left, right) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        ans = 0;
        maxHeight(root);
        return ans;
    }
};