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
private:
    TreeNode* ans, *target;
public:
    void dfs(TreeNode* original, TreeNode* cloned){
        if(!original){
            return;
        }
        dfs(original->left, cloned->left);
        if(original == target){
            ans = cloned;
        }
        dfs(original->right, cloned->right);
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        this->target = target;
        dfs(original, cloned);
        return ans;
    }
};