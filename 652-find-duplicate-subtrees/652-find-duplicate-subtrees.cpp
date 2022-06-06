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
    unordered_map<string, int> count;
    vector<TreeNode*> res;
public:
    string dfs(TreeNode* root){
        if(!root) return "";
        string node = to_string(root->val) + 
                    "," + dfs(root->left) +
                    "," + dfs(root->right);
        count[node]++;
        if(count[node] == 2) res.push_back(root);
        return node;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        return res;
    }
};