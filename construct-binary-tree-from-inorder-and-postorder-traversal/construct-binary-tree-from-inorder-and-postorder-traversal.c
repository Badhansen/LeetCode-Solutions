/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* go(int *inorder, int start, int end, int *postorder, int *pIndex){
    if(start > end)
        return NULL;
    struct TreeNode* ret = (struct TreeNode* )malloc(sizeof(struct TreeNode));
    ret->val = postorder[--(*pIndex)];
    ret->left = ret->right = NULL;
    int i;
    for(i = start; i <= end; i++){
        if(inorder[i] == ret->val) break;
    }
    ret->right = go(inorder, i + 1, end, postorder, pIndex);
    ret->left = go(inorder, start, i - 1, postorder, pIndex);
    return ret;
}

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize){
    int pIndex = postorderSize;
    return go(inorder, 0, inorderSize - 1, postorder, &pIndex);
}

