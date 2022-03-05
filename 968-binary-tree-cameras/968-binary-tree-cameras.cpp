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

class Solution {
private:
    int camera;
    enum Camera{
        HAS_CAMERA,
        COVERED,
        PLEASE_COVER,
    };
public:
    Camera dfs(TreeNode* root){
        if(root == NULL){
            return Camera::COVERED;
        }
        Camera left = dfs(root->left);
        Camera right = dfs(root->right);
        if(left == Camera::PLEASE_COVER || right == Camera::PLEASE_COVER){
            camera++;
            return Camera::HAS_CAMERA;
        }
        if(left == Camera::HAS_CAMERA || right == Camera::HAS_CAMERA){
            return Camera::COVERED;
        }
        return Camera::PLEASE_COVER;
    }
    int minCameraCover(TreeNode* root) {
        camera = 0;
        return dfs(root) == Camera::PLEASE_COVER ? ++camera : camera;
    }
};
/*
    Time Complexity: O(n)
    Space Complexity: O(h) dfs call stack or height of the binary tree
*/