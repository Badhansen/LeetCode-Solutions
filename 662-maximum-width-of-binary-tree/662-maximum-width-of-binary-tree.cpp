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
/*
// @Author: KING-SEN
// 1 last try

class Solution {
private:
    int maxWidth;
    unordered_map<int, long long> seen;
public:
    void dfs(TreeNode* root, int depth, int node){
        if(!root) return;
        if(!seen.count(depth)){
            seen[depth] = node;
        }
        int newNode = seen[depth];
        maxWidth = max(maxWidth, node - newNode + 1);
        dfs(root->left, depth + 1, 2ll * node + 1);
        dfs(root->right, depth + 1, 2ll * node + 2);
    }
    int widthOfBinaryTree(TreeNode* root) {
        dfs(root, 0, 0);
        return maxWidth;
    }
};

// Time: O(N), N = number of nodes
// Space: O(N), for recursion stack and store the node in map
*/

// @Author: KING-SEN
// 1 last try

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        int maxWidth = 0;
        queue<pair<TreeNode*, unsigned long long>> tree;
        tree.push({root, 0});
        while(!tree.empty()){
            int size = tree.size();
            int left = tree.front().second;
            int right = tree.back().second;
            maxWidth = max(maxWidth, right - left + 1);
            for(int i = 0; i < size; i++){
                auto node = tree.front();
                tree.pop();
                if(node.first->left) tree.push({node.first->left, 2ll * node.second + 1});
                if(node.first->right) tree.push({node.first->right, 2ll * node.second + 2});
            }
        }
        return maxWidth;
    }
};

// Time: O(N), N = number of nodes
// Space: O(N), for recursion stack and store the node in map