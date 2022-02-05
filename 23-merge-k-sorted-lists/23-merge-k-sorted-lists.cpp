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
    struct compare{
        bool operator()(const ListNode* a, const ListNode* b){
            return a->val > b->val;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> itemList;
        
        for(auto &el : lists){
            if(el){
                itemList.push(el);
            }
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* head = dummy;
        
        while(!itemList.empty()){
            ListNode* node = itemList.top();
            itemList.pop();
            
            head->next = node;
            head = head->next;
            
            if(node->next != NULL){
                itemList.push(node->next);
            }
        }
        return dummy->next;
    }
};

// Time Complexity: O(N log K), where N is the number of elements in the whole list, K is the number of list
// Space Complexity: O(N), N is the number of elements in the whole list
