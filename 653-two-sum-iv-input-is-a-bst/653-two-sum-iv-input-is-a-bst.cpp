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
    void solve(unordered_map<int, int>& seen, TreeNode* root){
        if(root == NULL) return;
        seen[root->val] = 1;
        solve(seen, root->left);
        solve(seen, root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int, int> seen;
        solve(seen, root);
        for(auto [key, val] : seen){
            int complement = k - key;
            if(seen.find(complement) != seen.end() && complement != key) return true;
        }
        return false;
    }
};