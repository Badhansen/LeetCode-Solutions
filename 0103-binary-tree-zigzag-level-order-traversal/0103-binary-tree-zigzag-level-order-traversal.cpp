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
    void solve(TreeNode* root, int level, vector<vector<int>>& answer){
        if(root == NULL) return;
        
        if(answer.size() == level){
            answer.push_back({});
        }
        
        answer[level].push_back(root->val);
        solve(root->left, level + 1, answer);
        solve(root->right, level + 1, answer);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> answer;
        solve(root, 0, answer);
        return answer;
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> answer;
        solve(root, 0, answer);
        for(int i = 0; i < answer.size(); i++){
            if(i & 1) reverse(answer[i].begin(), answer[i].end());
        }
        return answer;
    }
};