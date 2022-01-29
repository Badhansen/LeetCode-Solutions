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


// @author: KING-SEN
// Programming Language Used: C++

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(-1);
        ListNode* first = dummy;
        ListNode* second = dummy;
        
        dummy->next = head;
        
        for(int i = 1; i <= n + 1; i++){
            first = first->next;
        }
        
        while(first){
            first = first->next;
            second = second->next;
        }
        
        second->next = second->next->next;
        
        return dummy->next;
    }
};

// Time Complexity: O(N), where N is the length of the ListNode
// Space Complexity: O(1), We only used constant extra space. 
