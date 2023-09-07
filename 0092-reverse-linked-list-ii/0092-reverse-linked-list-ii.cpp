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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<int> v;
        ListNode* curr = head;
        int cnt = 0;
        while(curr){
            v.push_back(curr->val);
            curr = curr->next;
        }
        reverse(v.begin() + left - 1, v.begin() + right);
        curr = nullptr;
        for(auto &el : v){
            if(curr == nullptr){
                ListNode* temp = new ListNode(el);
                curr = temp;
                head = curr;
            }
            else{
                ListNode* temp = new ListNode(el);
                curr->next = temp;
                curr = curr->next;
            }
        }
        return head;
    }
};