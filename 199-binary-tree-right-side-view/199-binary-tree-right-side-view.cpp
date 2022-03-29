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
    map<int, int> leftView;
    vector<int> answer;
    void dfs(TreeNode* root, int level){
        if(root == NULL)
            return;
        if(leftView.find(level) == leftView.end()){
            leftView[level] = 1;
            answer.push_back(root->val);
        }
        dfs(root->right, level + 1);
        dfs(root->left, level + 1);
    }
    vector<int> rightSideView(TreeNode* root) {
        dfs(root, 0);
        return answer;
    }
};