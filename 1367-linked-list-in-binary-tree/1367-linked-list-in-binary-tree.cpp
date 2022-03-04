/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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

class Solution {
private:
    vector<int> pattern, lps;
    int pLen;
public:
    vector<int> listToArray(ListNode* head){
        vector<int> res;
        while(head){
            res.push_back(head->val);
            head =  head->next;
        }
        return res;
    }
    vector<int> createLps(vector<int>& pattern){
        int len = pattern.size();
        vector<int> lps(len, 0);
        for(int i = 1, j = 0; i < len; i++){
            while(j > 0 && pattern[i] != pattern[j]){
                j = lps[j - 1];
            }
            if(pattern[i] == pattern[j]){
                lps[i] = ++j;
            }
        }
        return lps;
    }
    bool kmpSearch(TreeNode* root, int pos){
        if(pos == pLen){
            return true;
        }
        if(root == NULL){
            return false;
        }
        while(pos > 0 && root->val != pattern[pos]){
            pos = lps[pos - 1];
        }
        if(root->val == pattern[pos]){
            pos++;
        } 
        return kmpSearch(root->left, pos) || kmpSearch(root->right, pos);
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        pattern = listToArray(head);
        pLen = pattern.size();
        lps = createLps(pattern);
        return kmpSearch(root, 0);
    }
};

// Time: O(m + n), where n is size of binary tree, m is size of linked list
// Space: O(h + m), h is height of the binary tree.
