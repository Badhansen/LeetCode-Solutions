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
private:
    vector<int> answer;
    stack<pair<int, int>> nextLarge;
public:
    int getLength(ListNode* head){
        ListNode* curr = head;
        int len = 0;
        while(head){
            head = head->next;
            len++;
        }
        return len;
    }
    vector<int> nextLargerNodes(ListNode* head) {
        int len = getLength(head);
        answer.resize(len, 0);
        for(int i = 0; i < len; i++){
            while(!nextLarge.empty() && head->val > nextLarge.top().first){
                answer[nextLarge.top().second] = head->val;
                nextLarge.pop();
            }
            nextLarge.push({head->val, i});
            head = head->next;
        }
        return answer;
    }
};