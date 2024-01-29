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
    void reorderList(ListNode* head) {
        vector<ListNode*> numbers;
        ListNode* curr = head;
        while(curr){
            numbers.push_back(curr);
            curr = curr->next;
        }
        int left = 1, right = numbers.size() - 1, cnt = 0;
        curr = head;
        while(cnt < numbers.size() - 1){
            if(cnt & 1){
                curr->next = numbers[left++];
            }
            else{
                curr->next = numbers[right--];
            }
            cnt++;
            curr = curr->next;
        }
        curr->next = NULL;
    }
};