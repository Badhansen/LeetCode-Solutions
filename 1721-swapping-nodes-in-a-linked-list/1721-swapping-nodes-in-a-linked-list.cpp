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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* firstNode = head, *secondNode = head;
        int length = 0;
        while(firstNode){
            firstNode = firstNode->next;
            length++;
        }
        firstNode = head;
        for(int i = 1; i < k; i++){
            firstNode = firstNode->next;
        }
        for(int i = 1; i < length - k + 1; i++){
            secondNode = secondNode->next;
        }
        swap(firstNode->val, secondNode->val);
        return head;
    }
};