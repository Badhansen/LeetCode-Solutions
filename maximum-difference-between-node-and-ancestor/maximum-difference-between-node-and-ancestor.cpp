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
    int ans, minVal, maxVal;
public:
    int dfs(TreeNode* root, int minVal, int maxVal){
        if(root == NULL)
            return maxVal - minVal;
        minVal = min(minVal, root->val);
        maxVal = max(maxVal, root->val);
        int left = dfs(root->left, minVal, maxVal);
        int right = dfs(root->right, minVal, maxVal);
        return max(left, right);
    }
    int maxAncestorDiff(TreeNode* root) {
        return dfs(root, INT_MAX, 0);
    }
};