class Solution {
public:
    TreeNode* LCA(TreeNode* root, int& a, int& b){
        if(!root || root->val == a || root->val == b) 
            return root;
        
        TreeNode* left = LCA(root->left, a, b);
        TreeNode* right = LCA(root->right, a, b);
        
        if(left && right)
            return root;
        return left ? left : right;
    }
    void getPath(TreeNode* root, int target, string& path, string &answer){
        if(!root) return;
        if(root->val == target){
            answer = path;
            return;
        }
        path.push_back('L');
        getPath(root->left, target, path, answer);
        path.pop_back();
        
        path.push_back('R');
        getPath(root->right, target, path, answer);
        path.pop_back();
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lca = LCA(root, startValue, destValue);
        string left, right, path;
        getPath(lca, startValue, path, left);
        getPath(lca, destValue, path, right);
        return string(left.size(), 'U') + right;
    }
};