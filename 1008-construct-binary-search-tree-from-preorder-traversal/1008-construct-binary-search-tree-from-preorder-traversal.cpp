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
    int pos = 0;
    TreeNode* rec(vector<int> &v, int low, int high){
        if(pos >= v.size() || v[pos] < low || v[pos] > high) 
            return NULL;
        
        TreeNode *root = new TreeNode(v[pos++]);
        
        root->left = rec(v, low, root->val);
        root->right = rec(v, root->val, high);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return rec(preorder, INT_MIN, INT_MAX);
    }
};
