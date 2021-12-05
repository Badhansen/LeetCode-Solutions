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
    bool dfs(TreeNode* root, int target, string& path){
        if(root->val == target) 
            return true;
        if(root->left && dfs(root->left, target, path))
            path.push_back('L');
        else if(root->right && dfs(root->right, target, path))
            path.push_back('R');
        return !path.empty();
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string left, right;
        TreeNode* lca = LCA(root, startValue, destValue);
        dfs(lca, startValue, left);
        dfs(lca, destValue, right);
        return string(left.size(), 'U') + string(right.rbegin(), right.rend());
    }
};