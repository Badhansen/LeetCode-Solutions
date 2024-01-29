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
    TreeNode* BuildTree(vector<int>& inorder, int left, int right, vector<int>& preorder, int& pre_index) {
        if (left > right) return NULL;
        int value = preorder[pre_index++];
        TreeNode* root = new TreeNode(value);
        int index = left;
        while (index <= right) {
            if (inorder[index] == value) {
                break;
            }
            index++;
        }
        root->left = BuildTree(inorder, left, index - 1, preorder, pre_index);
        root->right = BuildTree(inorder, index + 1, right, preorder, pre_index);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pre_index = 0;
        TreeNode* root = BuildTree(inorder, 0, inorder.size() - 1, preorder, pre_index);
        return root;
    }
};