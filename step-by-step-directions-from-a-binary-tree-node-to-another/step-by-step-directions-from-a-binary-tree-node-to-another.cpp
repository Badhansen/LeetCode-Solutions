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
    vector<int> graph[100001];
    int parent[100001];
    int level[100001];
    unordered_map<int, TreeNode*> seen;
public:
    void init(){
        for(int i = 0; i <= 100000; i++){
            graph[i].clear();
            parent[i] = i;
        }
    }
    void solve(TreeNode* root, int pr){
        if(root == NULL) 
            return;
        
        int u = root->val;
        seen[u] = root;
        
        if(pr != -1){
            graph[pr].push_back(u);
            graph[u].push_back(pr);
        }
        
        solve(root->left, u);
        solve(root->right, u);
    }
    int LCA(int a, int b){
        if(level[a] > level[b])
            swap(a, b);
        
        int diff = level[b] - level[a];
        while(diff != 0){
            b = parent[b];
            diff--;
        }
        
        if(a == b) return a;
        
        while(a != b){
            a = parent[a], b = parent[b];
        }
        
        return a;
    }
    
    void dfs(int node, int l, int p){
        level[node] = l;
        parent[node] = p;
        
        for(auto &v : graph[node]){
            if(v != p){
                dfs(v, l + 1, node);
            }
        }
    }
    
    string getDirections(TreeNode* root, int startValue, int destValue) {
        init();
        solve(root, -1);
        dfs(root->val, 0, -1);
        int lca = LCA(startValue, destValue);
        string left, right;
        
        while(startValue != lca){
            startValue = parent[startValue];
            left.push_back('U');
            
        }
        
        while(destValue != lca){
            int temp = destValue;
            destValue = parent[destValue];
            
            if(seen[destValue]->left && seen[destValue]->left->val == temp){
                right.push_back('L');
            }
            else{
                right.push_back('R');
            }
        }
        
        reverse(right.begin(), right.end());
        
        return left + right;
    }
};