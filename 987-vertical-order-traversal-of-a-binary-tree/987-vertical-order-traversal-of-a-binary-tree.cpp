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
    map<int, vector<pair<int, int>> > mp;
    void rec(TreeNode* root, int i, int j){
        if(root == NULL){
            return;
        }
        mp[i].push_back({j, root->val});
        rec(root->left, i - 1, j + 1);
        rec(root->right, i + 1, j + 1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        rec(root, 0, 0);
        for(auto n : mp){
            sort(n.second.begin(), n.second.end());
            vector<int> tmp;
            for(auto &p : n.second){
                tmp.push_back(p.second);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};