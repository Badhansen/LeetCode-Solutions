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
    void Dfs(TreeNode* root, int level, vector<int> &level_sum) {
        if (!root) {
            return;
        }
        if (level == level_sum.size()) {
            level_sum.push_back(0);
        }
        level_sum[level] += root->val;
        Dfs(root->left, level + 1, level_sum);
        Dfs(root->right, level + 1, level_sum);
    }
    int maxLevelSum(TreeNode* root) {
        vector<int> level_sum;
        Dfs(root, 0, level_sum);
        int small_level = INT_MAX, max_sum = INT_MIN;
        for (int i = 0; i < level_sum.size(); i++) {
            if (max_sum < level_sum[i]) {
                small_level = i + 1;
                max_sum = level_sum[i];
            }
        }
        return small_level;
    }
};