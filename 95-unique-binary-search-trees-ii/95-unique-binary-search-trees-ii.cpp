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
    vector<TreeNode*> rec(int l, int r){
        vector<TreeNode*> temp;
        if(l > r){
            temp.push_back(NULL);
            return temp;
        }
        for(int i = l; i <= r; i++){
            //cout << l << " " << i - 1 << endl;
            vector<TreeNode*> left = rec(l, i - 1);
            //cout << i + 1 << " " << r << endl;
            vector<TreeNode*> right = rec(i + 1, r);
            for(auto x : left){
                for(auto y : right){
                    
                    TreeNode *curr = new TreeNode(i);
                    curr->left = x;
                    curr->right = y;
                    temp.push_back(curr);
                }
            }
        }
        return temp;
    }
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0){
            vector<TreeNode*> v;
            return v;
        }
        return rec(1, n);
    }
};