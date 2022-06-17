/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


#define NO_CAMERA       0
#define HAS_CAMERA      2
#define NOT_NEEDED      1

class Solution {
private:
    int ans = 0;
public:
    int dfs(TreeNode *root) {
        if (!root) return NOT_NEEDED;
        
        int l = dfs(root->left);
        int r = dfs(root->right);
        
        if (l == NO_CAMERA || r == NO_CAMERA) {
            ans++;
            return HAS_CAMERA;
        } 
        else if (l == HAS_CAMERA || r == HAS_CAMERA) {
            return NOT_NEEDED;
        } 
        else {
            return NO_CAMERA;
        }
    }
    int minCameraCover(TreeNode* root) {
        if (dfs(root) == NO_CAMERA) ans++;
        return ans;
    }
};

// Time: O(N), N = number of nodes
// Space: O(recursion stack)



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
         A tree has 3 states
           ()
          /  \
         ()  () <- Node not covered
        /  \
       ()  (c) <- node with camera
          /
         () <- Node covered with camera 
*/
/*
class Solution {
private:
    int camera;
    unordered_map<TreeNode*, bool> covered;
public:
    void dfs(TreeNode* root, TreeNode* parent){
        if(root == NULL){
            return;
        }
        dfs(root->left, root);
        dfs(root->right, root);
        if(parent == NULL && !covered.count(root) ||
                             !covered.count(root->left) ||
                             !covered.count(root->right)){
            camera++;
            covered[root] = true;
            covered[parent] = true;
            covered[root->left] = true;
            covered[root->right] = true;
        }
    }
    int minCameraCover(TreeNode* root) {
        camera = 0;
        covered[NULL] = true;
        dfs(root, NULL);
        return camera;
    }
};
/*
    Time Complexity: O(n)
    Space Complexity: O(h) dfs call stack or height of the binary tree
*/