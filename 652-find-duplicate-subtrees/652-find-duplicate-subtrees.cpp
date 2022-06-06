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
private:
    unordered_map<string, int> stoIndex;
    unordered_map<int, int> count;
    vector<TreeNode*> res;
    int index = 1;
public:
    int dfs(TreeNode* root){ // O(N)
        if(!root) return 0;
        
        int leftId = dfs(root->left);
        int rightId = dfs(root->right);
        
        string node = to_string(leftId) + "," + to_string(root->val) + "," + to_string(rightId);
        
        int id = stoIndex[node];
        if(id == 0){
            id = index++;
            stoIndex[node] = id;
        }
        
        count[id]++;
        if(count[id] == 2) res.push_back(root);
        
        return id;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        return res;
    }
};

// Time: O(N), N = number of nodes
// Spce: O(N)