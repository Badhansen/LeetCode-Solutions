/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* go(ListNode* a, ListNode* b){
        if(b->next == NULL) return a;
        if(b->next->next == NULL) return a->next;
        return go(a->next, b->next->next);
    }
    ListNode* middleNode(ListNode* head) {
        return go(head, head);
    }
};