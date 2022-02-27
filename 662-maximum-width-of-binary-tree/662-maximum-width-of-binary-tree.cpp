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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL)
            return 0;
        int answer = 1;
        queue<pair<TreeNode*, long long>> qt;
        qt.push({root, 0});
        while(qt.empty() == false){
            int _size = qt.size();
            int start = qt.front().second;
            int end = qt.back().second;
            answer = max(answer, end - start + 1);
            for(int i = 0; i < _size; i++){
                TreeNode* t = qt.front().first;
                long long idx = qt.front().second - start;
                qt.pop();
                if(t->left){
                    qt.push({t->left, idx * 2 + 1});
                }
                if(t->right){
                    qt.push({t->right, idx * 2 + 2});
                }
            }
        }
        return answer;
    }
};