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
    pair<int, int> helper(TreeNode* root){
        // Base case return as [rob, notRob] as pair answer
        if(root == NULL){
            return {0, 0}; 
        }
        
        pair<int, int> left = helper(root->left);
        pair<int, int> right = helper(root->right);
        
        int rob = root->val + left.second + right.second;
        int notRob = max(left.first, left.second) + max(right.first, right.second);
        
        return {rob, notRob};
    }
    int rob(TreeNode* root) {
        pair<int, int> answer = helper(root);
        
        return max(answer.first, answer.second);
    }
};


// Time Complexity: O(N), here N = Number of nodes in the binary tree
// Space Complexity: O(N), since we need stack to do recursion ans the maximum depth of the 
// recursion is the height of the tree, which is O(N) in the worst case and O(log N) in the best case



