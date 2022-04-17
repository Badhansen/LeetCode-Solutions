/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int ans = 0;
void rec(struct TreeNode* root, int sum){
    if(root == NULL) return;
    sum = sum * 10 + root->val;
    if(root->left == NULL && root->right == NULL){
        ans += sum;
    }
    rec(root->left, sum);
    rec(root->right, sum);
}
int sumNumbers(struct TreeNode* root){
    ans = 0;
    rec(root, 0);
    return ans;
}

