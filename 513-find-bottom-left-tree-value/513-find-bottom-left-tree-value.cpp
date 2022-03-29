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
    int deepest = -1;
    int answer;
public:
    void dfs(TreeNode* root, int deep){
        if(root == NULL){
            return;
        }
        if(deep > deepest){
            answer = root->val;
            deepest = deep;
        }
        dfs(root->left, deep + 1);
        dfs(root->right, deep + 1);
    }
    int findBottomLeftValue(TreeNode* root) {
        dfs(root, 0);
        return answer;
    }
};