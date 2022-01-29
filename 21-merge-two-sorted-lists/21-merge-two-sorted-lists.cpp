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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) 
            return l2;
        if(l2 == NULL) 
            return l1;
        if(l1->val <= l2->val){
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else{
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};

// Time Complexity: O(N + M), where N and M are the length of l1 and l2 list respectively
// Space Complexity: O(N + M), The first call to mergeTwoLists does not return until the ends of both l1 and l2 have been reached, so N + M stack frames consume O(N + M) space.