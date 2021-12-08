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
private:
    int answer = 0;
public:
    int dfs(TreeNode* root){
        if(!root) return 0;
        
        int left = dfs(root->left);
        int right = dfs(root->right);
        
        answer += abs(left - right);
        
        return left + right + root->val;
    }
    int findTilt(TreeNode* root) {
        answer = 0;
        dfs(root);
        return answer;
    }
};