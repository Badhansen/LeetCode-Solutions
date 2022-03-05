/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// @Author: KING-SEN

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = dfs(root);
        return s;
    }
    string dfs(TreeNode* root){
        if(root == NULL){
            return "*";
        }
        string item = to_string(root->val);
        return item + "," + dfs(root->left) + "," + dfs(root->right);
    }
    
    TreeNode* makeTree(queue<string>& qt){
        string num = qt.front();
        qt.pop();
        if(num == "*"){
            return NULL;
        }
        int val = stoi(num);
        TreeNode* root = new TreeNode(val);
        root->left = makeTree(qt);
        root->right = makeTree(qt);
        return root;
    }
    queue<string> bfs(string& data){
        string num = "";
        queue<string> qt;
        for(auto c : data){
            if(c == ','){
                qt.push(num);
                num = "";
            }
            else{
                num.push_back(c);
            }
        }
        qt.push(num);
        return qt;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> qt = bfs(data);
        return makeTree(qt);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));