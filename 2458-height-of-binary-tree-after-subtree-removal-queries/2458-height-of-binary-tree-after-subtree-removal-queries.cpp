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
    unordered_map<int, int> left, right, height;
public:
    int Height(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int lh = Height(root->left);
        int rh = Height(root->right);
        left[root->val] = lh;
        right[root->val] = rh;
        return max(lh, rh) + 1;
    }
    void Solve(TreeNode* root, int maxh, int depth) {
        if (!root) {
            return;
        }
        height[root->val] = maxh;
        Solve(root->left, max(maxh, depth + right[root->val]), depth + 1);
        Solve(root->right, max(maxh, depth + left[root->val]), depth + 1);
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        Height(root);
        Solve(root->left, right[root->val], 1);
        Solve(root->right, left[root->val], 1);
        vector<int> answer;
        for (auto &q : queries) {
            answer.push_back(height[q]);
        }
        return answer;
    }
};