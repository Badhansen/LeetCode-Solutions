// @Author: KING-SEN
// 1 last try

class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(!root) 
            return NULL;
        
        root->left = removeLeafNodes(root->left, target);
        root->right = removeLeafNodes(root->right, target);
        
        if(root->left == NULL && root->right == NULL && root->val == target) 
            return NULL;
        
        return root;
    }
};

// time : O(N), N = Number of nodes
// space : O(depth of the tree)