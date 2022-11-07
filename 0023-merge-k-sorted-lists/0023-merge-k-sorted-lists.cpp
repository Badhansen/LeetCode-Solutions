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

//@Author: KING-SEN
// Progrmming Language Used: C++

class Solution {
public:    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> que;
        for(int i = 0; i < n; i++){
            if(lists[i] == NULL) continue;
            que.push({lists[i]->val, lists[i]->next});
        }
        ListNode* root = new ListNode(-1), *curr;
        curr = root;
        while(!que.empty()){
            auto top = que.top();
            que.pop();
            curr->next = new ListNode(top.first);
            curr = curr->next;
            ListNode* nnode = top.second;
            if(nnode){
                que.push({nnode->val, nnode->next});
            }
        }
        return root->next;
    }
};

// Time Complexity: O(N log K), where N is the number of elements in the whole list, K is the number of list
// Space Complexity: O(N), N is the number of elements in the whole list
