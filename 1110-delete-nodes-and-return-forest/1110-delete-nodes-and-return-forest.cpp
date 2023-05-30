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
    set<int> seen;
    vector<TreeNode*> answer;
public:
    TreeNode* Dfs(TreeNode* root) {
        if (!root) {
            return NULL;
        }
        root->left = Dfs(root->left);
        root->right = Dfs(root->right);
        if (seen.count(root->val)) {
            if (root->left) {
                answer.push_back(root->left);
            }
            if (root->right) {
                answer.push_back(root->right);
            }
            return NULL;
        }
        return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for (auto &d : to_delete) {
            seen.insert(d);
        }
        if (!seen.count(root->val)) {
            answer.push_back(root);
        }
        Dfs(root);
        return answer;
    }
};