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
// 1 last try


class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr)
        {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* curr = head;
        ListNode* newList = NULL;
        ListNode* tail = NULL;
        while(curr){
            if(newList == NULL){
                newList = new ListNode(curr->val);
                tail = newList;
            }
            else{
                tail->next = new ListNode(curr->val);
                tail = tail->next;
            }
            curr = curr->next;
        }
        head = reverse(head);
        while(newList && head){
            if(newList->val != head->val)
                return false;
            newList = newList->next;
            head = head->next;
        }
        return true;
    }
};