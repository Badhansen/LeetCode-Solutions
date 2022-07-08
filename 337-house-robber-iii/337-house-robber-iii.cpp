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
        if(root == NULL){
            return {0, 0}; 
        }
        
        pair<int, int> leftRes = dfs(root->left);
        pair<int, int> rightRes = dfs(root->right);
        
        int rob = root->val + leftRes.second + rightRes.second;
        int notRob = max(leftRes.first, leftRes.second) + max(rightRes.first, rightRes.second);
        
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



