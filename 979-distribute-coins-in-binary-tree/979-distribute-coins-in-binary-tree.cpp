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
/*
Below is the basic intuition behind this problem:

    * Root asks the left subtree, how much do you need or you've got extra? I'll give that/take it away to/from you via our direct edge, and pass it to right child, and if something remains, I'll take it.
    * Same question is asked to the right child.
    * Answer will be the sum of values(absolute) returned after the asked questions from the left(Left) and right(Right).
    * But what should the root return to its parent? It will return that how much does "his tree" need/has extra. That will be the signed sum of its Left+Right (question's answer) + same question asked to current root node.

*/
class Solution {
public:
    int dfs(TreeNode* root, int &moves){
        if(root == NULL){
            return 0;
        }
        int left = dfs(root->left, moves) ;
        int right = dfs(root->right, moves);
        moves += abs(left) + abs(right);
        return root->val + left + right - 1;
    }
    int distributeCoins(TreeNode* root) {
        int moves = 0;
        dfs(root, moves);
        return moves;
    }
};