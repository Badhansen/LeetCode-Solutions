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
    unordered_map<int, int> seen;
    
    void dfs(TreeNode* root){
        if(root == NULL){
            return;
        }
        
        seen[root->val]++;
        
        dfs(root->left);
        dfs(root->right);
    }
    
    vector<int> findMode(TreeNode* root) {
        dfs(root);
        
        int maximum = 0;
        
        for(auto &item : seen){
            if(item.second > maximum){
                maximum = item.second;
            }
        }
        
        vector<int> answer;
        
        for(auto &item : seen){
            if(item.second == maximum){
                answer.push_back(item.first);
            }
        }
        
        return answer;
    }
};

// Time Complexity: O(N), where N is the number of nodes in the tree
// Space Complexity: O(N), we have to store the count in map