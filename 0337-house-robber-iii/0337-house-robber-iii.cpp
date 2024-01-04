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

// @Author: KING-SEN
// Programming Language Used: C++

class Solution {
public:
    pair<int, int> dfs(TreeNode* root){
        // Base case return as [rob, notRob] as pair answer
        if (root == NULL) {
            return {0, 0};
        }
        auto leftResult = dfs(root->left);
        auto rightResult = dfs(root->right);
        int rob = root->val + leftResult.second + rightResult.second;
        int notRob = max(leftResult.first, leftResult.second) + max(rightResult.first, rightResult.second);
        return {rob, notRob};
    }
    int rob(TreeNode* root) {
        pair<int, int> answer = dfs(root);
        return max(answer.first, answer.second);
    }
};


// Time Complexity: O(N), here N = Number of nodes in the binary tree
// Space Complexity: O(N), since we need stack to do recursion ans the maximum depth of the 
// recursion is the height of the tree, which is O(N) in the worst case and O(log N) in the best case



