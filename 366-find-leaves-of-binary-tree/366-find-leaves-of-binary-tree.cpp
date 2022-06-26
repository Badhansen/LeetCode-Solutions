// @Author: KING-SEN
// Programming Language Used: C++

class Solution {
public:
    int dfs(TreeNode* root, vector<vector<int>>& result){
        if(!root) return 0;
        
        int leftDepth = dfs(root->left, result);
        int rightDepth = dfs(root->right, result);
        
        int maxLevel = max(leftDepth, rightDepth);
        
        if(maxLevel == result.size()) result.push_back({});
        
        result[maxLevel].push_back(root->val);
        
        return maxLevel + 1;
    }
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> result;
        
        dfs(root, result);
        
        return result;
    }
};

//Time Complexity: O(N), Here N = total number of nodes in the binary tree 
// Traversing the tree takes O(N) time and storing all the pair the currect position also
// take O(N) time. Hence overall time complexity of this approach is O(N)

// Space Complexity: O(N), The space taken by solution array

