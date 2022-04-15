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
static int ConfigureFastIo(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}
static int unused = ConfigureFastIo();
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if(root == NULL)
            return NULL;
        root->left = trimBST(root->left, L, R);
        root->right = trimBST(root->right, L, R);
        if(root->val >= L && root->val <= R)
            return root;
        if(root->left)
            return root->left;
        else
            return root->right;
    }
};