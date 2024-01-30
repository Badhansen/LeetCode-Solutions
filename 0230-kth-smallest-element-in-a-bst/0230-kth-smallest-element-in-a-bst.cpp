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
    void Dfs(TreeNode* root, int& k, int& answer) {
        if (!root) {
            return;
        }
        Dfs(root->left, k, answer);
        k--;
        if (k == 0) {
            answer = root->val;
            return;
        }
        Dfs(root->right, k, answer);
    }
    int kthSmallest(TreeNode* root, int k) {
        int answer;
        Dfs(root, k, answer);
        return answer;
    }
};