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

// 1 last try

class Solution {
public:
    string tree2str(TreeNode* root) {
        if(!root) return "";
        if(root->left == NULL && root->right == NULL)
            return to_string(root->val);
        if(root->right == NULL) 
            return to_string(root->val) + "(" + tree2str(root->left) + ")";
        return to_string(root->val) + "(" + tree2str(root->left) + ")(" + tree2str(root->right) + ")";
    }
};

// time: O(n), n= nummber of nodes
// space: O(n), as the depth of the recursion tree can go upto n