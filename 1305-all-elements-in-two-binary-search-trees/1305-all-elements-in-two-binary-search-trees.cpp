/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> v;
    void rec(TreeNode* root){
        if(root == NULL) return;
        v.push_back(root->val);
        rec(root->left);
        rec(root->right);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        rec(root1);
        rec(root2);
        sort(v.begin(), v.end());
        return v;
    }
};