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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* curr = head;
        vector<int> numbers;
        
        while(curr != NULL){
            numbers.push_back(curr->val);
            curr = curr->next;
        }
        
        sort(numbers.begin(), numbers.end());
        curr = head;
        int i = 0;
        
        while(curr){
            curr->val = numbers[i];
            i++;
            curr = curr->next;
        }
        
        return head;
    }
};