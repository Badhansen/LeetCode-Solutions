/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct Node{
    TreeNode *l, *r;
};
class Solution {
public:
    /*
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1 == NULL) return t2;
        else if(t2 == NULL) return t1;
        t1->val += t2->val;
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);
        return t1;
    }
    */
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        stack<Node> st;
        if(t1 == NULL) return t2;
        else if(t2 == NULL) return t1;
        Node t;
        t.l = t1;
        t.r = t2;
        st.push(t);
        while(!st.empty()){
            Node p = st.top();
            st.pop();
            if(p.l == NULL || p.r == NULL) continue;
            //cout << p.l->val << " " << p.r->val << endl;
            
            p.l->val += p.r->val;
            if(p.l->left == NULL){
                p.l->left = p.r->left;
            }
            else{
                Node t; 
                t.l = p.l->left; 
                t.r = p.r->left;
                st.push(t);
            }
            if(p.l->right == NULL){
                p.l->right = p.r->right;
            }
            else{
                Node t; 
                t.l = p.l->right; 
                t.r = p.r->right;
                st.push(t);
            }
        }
        return t1;   
    }
};