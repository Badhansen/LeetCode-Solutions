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
    int ret, ind;
    void rec(ListNode* head){
        if(head == NULL) return;
        rec(head->next);
        ret += ((head->val) * pow(2, ind));
        ind++;
    }
    int getDecimalValue(ListNode* head) {
        ret = 0;
        ind = 0;
        rec(head);
        return ret;
    }
};