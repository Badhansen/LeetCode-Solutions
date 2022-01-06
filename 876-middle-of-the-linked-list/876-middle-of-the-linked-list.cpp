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
    ListNode* go(ListNode* a, ListNode* b){
        if(b->next == NULL)
            return a;
        if(b->next->next == NULL)
            return a->next;
        return go(a->next, b->next->next);
    }
    ListNode* middleNode(ListNode* head) {
        ListNode* fast, *slow;
        fast = head;
        slow = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};