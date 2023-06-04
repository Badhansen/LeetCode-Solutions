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
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL)
            return root;
        
        TreeNode* left = invertTree(root->left);
        TreeNode* right = invertTree(root->right);
        
        root->left = right;
        root->right = left;
        
        return root;
    }
};
/*
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return NULL;
        
        stack<TreeNode*> seen;
        seen.push(root);
        
        while(!seen.empty()){
            TreeNode* node = seen.top();
            seen.pop();
            if(node->left) seen.push(node->left);
            if(node->right) seen.push(node->right);
            swap(node->left, node->right);
            // TreeNode* temp = node->left;
            // node->left = node->right;
            // node->right = temp;
            
        }
        return root;
    }
};

// Time complexity: O(N), where N is the total number of nodes
// Space complexity: O(N), since in the worst case, the queue will contain all nodes in one level of the binary tree.
*/