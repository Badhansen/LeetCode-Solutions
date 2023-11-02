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
    pair<int, int> get(TreeNode* root, int &res) {
        if (root == NULL) {
            return {0, 0};
        }
        auto left = get(root->left, res);
        auto right = get(root->right, res);
        
        int sum = left.first + right.first + root->val;
        int nodes = left.second + right.second + 1;
        if ((sum / nodes) == root->val) {
            res++;
        }
        return {sum, nodes};
    }
    int averageOfSubtree(TreeNode* root) {
        int res = 0;
        auto ans = get(root, res);
        return res;
    }
};