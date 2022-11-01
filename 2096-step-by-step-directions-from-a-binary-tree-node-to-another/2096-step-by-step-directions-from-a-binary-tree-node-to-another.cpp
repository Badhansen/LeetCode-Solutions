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
    TreeNode* LowestCommonAncestor(TreeNode* root, int u, int v) {
        if (!root || root->val == u || root->val == v) {
            return root;
        }
        
        TreeNode* left = LowestCommonAncestor(root->left, u, v);
        TreeNode* right = LowestCommonAncestor(root->right, u, v);
        
        if (left && right) {
            return root;
        }
        return left ? left : right;
    }
    void Dfs(TreeNode* root, int target, string& path, string& answer) {
        if (!root) {
            return;
        }
        if (root->val == target) {
            answer = path;
            return;
        }
        path.push_back('L');
        Dfs(root->left, target, path, answer);
        path.pop_back();
        path.push_back('R');
        Dfs(root->right, target, path, answer);
        path.pop_back();
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lca = LowestCommonAncestor(root, startValue, destValue);
        string left, right, path;
        Dfs(lca, startValue, path, left);
        Dfs(lca, destValue, path, right);
        return string(left.size(), 'U') + right;
    }
};
// Time: O(N)
// Space: O(M)