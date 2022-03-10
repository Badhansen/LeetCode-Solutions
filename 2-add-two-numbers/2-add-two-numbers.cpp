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
        ListNode* curr, *root = NULL;
        int carry = 0;
        while(l1 || l2){
            if(l1 != NULL && l2 != NULL){
                ListNode* t = new ListNode;
                t->val = (l1->val + l2->val + carry) % 10;
                t->next = NULL;
                carry = (l1->val + l2->val + carry) / 10;
                if(root == NULL){
                    curr = root = t;
                }
                else{
                    curr->next = t;
                    curr = curr->next;
                }
                l1 = l1->next;
                l2 = l2->next;
            }
            else if(l1 == NULL){
                ListNode* t = new ListNode;
                t->val = (l2->val + carry) % 10;
                t->next = NULL;
                carry = (l2->val + carry) / 10;
                if(root == NULL){
                    curr = root = t;
                }
                else{
                    curr->next = t;
                    curr = curr->next;
                }
                l2 = l2->next;
            }
            else if(l2 == NULL){
                ListNode* t = new ListNode;
                t->val = (l1->val + carry) % 10;
                t->next = NULL;
                carry = (l1->val + carry) / 10;
                if(root == NULL){
                    curr = root = t;
                }
                else{
                    curr->next = t;
                    curr = curr->next;
                }
                l1 = l1->next;
            }
        }
        if(carry){
            ListNode* t = new ListNode;
            t->val = carry;
            t->next = NULL;
            curr->next = t;
        }
        return root;
    }
};