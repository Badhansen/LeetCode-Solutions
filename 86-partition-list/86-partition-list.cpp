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
    ListNode* partition(ListNode* head, int x) {
        ListNode *currLow, *currLowHead, *currHigh, *currHighHead;
        currLowHead = new ListNode(0);
        currLow = currLowHead;
        currHighHead = new ListNode(0);
        currHigh = currHighHead;
        while(head != NULL){
            if(head->val < x){
                currLow->next = head;
                currLow = currLow->next;
            }
            else{
                currHigh->next = head;
                currHigh = currHigh->next;
            }
            head = head->next;
        }
        currHigh->next = NULL;
        currLow->next = currHighHead->next;
        return currLowHead->next;
    }
    
};