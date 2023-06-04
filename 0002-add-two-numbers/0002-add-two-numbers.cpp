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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(-1);
        ListNode *curr = dummy;
        int carry = 0;
        while(l1 || l2 || carry){
            int value = carry;
            if(l1){
                value += l1->val; 
                l1 = l1->next;
            }
            if(l2) {
                value += l2->val; 
                l2 = l2->next;
            }
            carry = value / 10; 
            value %= 10;
            curr->next = new ListNode(value); 
            curr = curr->next;
        }
        return dummy->next;
    }
};
