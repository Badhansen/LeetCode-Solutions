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
    void dfs(TreeNode* root, vector<TreeNode*>& ret){
        if(!root){
            return;
        }
        ret.push_back(root);
        dfs(root->left, ret);
        dfs(root->right, ret);
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        vector<TreeNode*> ans1, ans2;
        dfs(original, ans1);
        dfs(cloned, ans2);
        for(int i = 0; i < ans1.size(); i++){
            if(ans1[i] == target){
                return ans2[i];
            }
        }
        return NULL;
    }
};