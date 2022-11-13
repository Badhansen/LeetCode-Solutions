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
    ListNode* ReverseList(ListNode* head) {
        ListNode* curr = head, *prev = NULL;
        while (curr != NULL) {
            ListNode* next_node = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_node;
        }
        return prev;
    }
    ListNode* GetMid(ListNode* head) {
        ListNode* fast = head, *slow = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    bool isPalindrome(ListNode* head) {
        if (head == NULL) {
            return true;
        }
        ListNode* first_half_end = GetMid(head);
        ListNode* second_half_start = ReverseList(first_half_end->next);
        ListNode* ptr1 = head;
        ListNode* ptr2 = second_half_start;
        bool result = true;
        while (result && ptr2 != NULL) {
            if (ptr1->val != ptr2->val) {
                result = false;
            }
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        first_half_end = ReverseList(second_half_start);
        return result;
    }
};