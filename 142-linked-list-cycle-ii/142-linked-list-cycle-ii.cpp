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
    ListNode *detectCycle(ListNode *head) {
        ListNode* curr = head;
        unordered_map<ListNode*, bool> seen;
        while(curr){
            if(seen.count(curr)){
                return curr;
            }
            seen[curr] = true;
            curr = curr->next;
        }
        return NULL;
    }
};