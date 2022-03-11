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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)
            return head;
        int cnt = 1; 
        ListNode* curr = head, *temp;
        while(curr->next){
            cnt++;
            curr = curr->next;
        }
        k = k % cnt;
        if(k % cnt){
            curr->next = head;
            curr = head;
            for(int i = 0; i < cnt - k - 1; i++){
                curr = curr->next;
            }
            head = curr->next;
            curr->next = NULL;
            
            return head;
        }
        return head;
    }
};