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
    int Dfs(TreeNode* root, int& answer) {
        if (!root) {
            return 0;
        }
        int left_sum = max(0, Dfs(root->left, answer));
        int right_sum = max(0, Dfs(root->right, answer));
        answer = max(answer, left_sum + right_sum + root->val);
        return root->val + max(left_sum, right_sum);
    }
    int maxPathSum(TreeNode* root) {
        int answer = INT_MIN;
        Dfs(root, answer);
        return answer;
    }
};