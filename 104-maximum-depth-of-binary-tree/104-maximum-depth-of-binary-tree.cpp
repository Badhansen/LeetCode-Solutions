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
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        
        queue<TreeNode*> path;
        
        path.push(root);
        int height = 0;
        
        while(!path.empty()){
            int size = path.size();
            while(size--){
                TreeNode* node = path.front();
                path.pop();
                
                if(node->left){
                    path.push(node->left);
                }
                if(node->right){
                    path.push(node->right);
                }
            }
            height++;
        }
        
        return height;
    }
};

