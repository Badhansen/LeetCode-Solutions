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
    void solve(TreeNode* root, int sum, int targetSum, vector<int> path, vector<vector<int>>& answer){
        if(root == NULL) return;
        
        path.push_back(root->val);
        
        if(root->left == NULL && root->right == NULL){
            if(sum + root->val == targetSum){
                answer.push_back(path);
            }
            return;
        }
        solve(root->left, sum + root->val, targetSum, path, answer);
        solve(root->right, sum + root->val, targetSum, path, answer);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> answer;
        vector<int> path;
        solve(root, 0, targetSum, path, answer);
        return answer;
    }
};