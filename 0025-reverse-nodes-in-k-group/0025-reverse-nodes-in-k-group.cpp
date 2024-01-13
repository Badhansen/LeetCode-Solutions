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


// @Author: KING-SEN

class Solution {
public: 
    ListNode* reverseLinkList(ListNode* head, int k) {
        ListNode* prev = NULL, *curr = head;
        while (k--) {
            ListNode* newNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = newNode;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count = 0;
        ListNode* curr = head;
        while (count < k && curr != NULL) {
            count++;
            curr = curr->next;
        }
        if (count == k) {
            ListNode* reverseHead = reverseLinkList(head, k);
            head->next = reverseKGroup(curr, k);
            return reverseHead;
        }
        return head;
    }
};