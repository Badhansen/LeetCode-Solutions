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
    vector<int> start, end, depth;
public:
    int CountNode(TreeNode* root) {
        if (!root) {
            return 0;
        }
        return 1 + CountNode(root->left) + CountNode(root->right);
    }
    void CalculateDepth(TreeNode* root, int level) {
        if (root->left) {
            CalculateDepth(root->left, level + 1);
        }
        if (root->right) {
            CalculateDepth(root->right, level + 1);
        }
        depth[start[root->val]] = level;
    }
    void EulerTour(TreeNode* root, int& index) {
        start[root->val] = index;
        if (root->left) {
            index++;
            EulerTour(root->left, index);
        }
        if (root->right) {
            index++;
            EulerTour(root->right, index);
        }
        end[root->val] = index;
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        int n = CountNode(root);
        start.resize(n + 1), end.resize(n + 1), depth.resize(n + 1);
        int index = 1;
        EulerTour(root, index);
        CalculateDepth(root, 0);
        vector<int> prefix_max(n + 2, 0), suffix_max(n + 2, 0);
        for (int j = 1; j <= n; j++) {
            prefix_max[j] = max(depth[j], prefix_max[j - 1]);
        }
        for (int j = n; j >= 1; j--) {
            suffix_max[j] = max(depth[j], suffix_max[j + 1]);
        }
        vector<int> answer;
        for (auto &q : queries) {
            int l = start[q], r = end[q];
            answer.push_back(max(prefix_max[l - 1], suffix_max[r + 1]));
        }
        return answer;
    }
};