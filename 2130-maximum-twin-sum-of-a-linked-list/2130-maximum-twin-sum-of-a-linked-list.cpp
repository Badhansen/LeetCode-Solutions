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
    int pairSum(ListNode* head) {
        ListNode* slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* next, *prev = NULL;
        while (slow) {
            next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }
        int answer = 0;
        while (prev) {
            answer = max(answer, head->val + prev->val);
            prev = prev->next;
            head = head->next;
        }
        return answer;
    }
};