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
    
    int arr[1000001];
    int ind;
    void go(struct TreeNode* root){
        if(root == NULL) return;
        go(root->left);
        arr[ind++] = root->val;
        go(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        ind = 0;
        go(root);
        return arr[k - 1];
    }
};