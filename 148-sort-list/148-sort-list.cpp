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
    ListNode* getMid(ListNode* head){
        ListNode* slow = head, *fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* list1, ListNode* list2){
        ListNode temp(0);
        ListNode* curr = &temp;
        while(list1 && list2){
            if(list1->val < list2->val){
                curr->next = list1;
                list1 = list1->next;
            }
            else{
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }
        if(list1)
            curr->next = list1;
        else
            curr->next = list2;
        return temp.next;
    }
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode* mid = getMid(head);
        ListNode* right = sortList(mid->next);
        mid->next = NULL;
        ListNode* left = sortList(head);
        
        return merge(left, right);
    }
};