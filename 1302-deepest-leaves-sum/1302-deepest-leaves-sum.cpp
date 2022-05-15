/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int l, r;
    vector<int> dp[20001];
    int ans = 0;
    void rec(TreeNode* root, int cnt){
        if(root == NULL){
            return;
        }
        dp[cnt].push_back(root->val);
        rec(root->left, cnt + 1);
        rec(root->right, cnt + 1);
        ans = max(ans, cnt);
    }
    int deepestLeavesSum(TreeNode* root) {
        rec(root, 0);
        int sum = 0;
        for(auto x : dp[ans]){
            sum += x;
        }
        return sum;
    }
};