/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

const int kLevel = 105;

class Solution {
public:
    void Dfs(TreeNode* root, std::vector<int>& path, int level, std::vector<std::string>& answer) {
        if (!root) {
            return;
        }
        path[level] = root->val;
        if (root->left == NULL && root->right == NULL) {
            string leave_path;
            for (int i = 0; i <= level; i++) {
                leave_path.append(to_string(path[i]));
                if (i != level) {
                    leave_path.append("->");
                }
            }
            answer.push_back(leave_path);
            return;
        }
        Dfs(root->left, path, level + 1, answer);
        Dfs(root->right, path, level + 1, answer);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        std::vector<std::string> answer;
        std::vector<int> path(kLevel);
        Dfs(root, path, 0, answer);
        return answer;
    }
};