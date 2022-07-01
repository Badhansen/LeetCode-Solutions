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
    vector<int> nextLargerNodes(ListNode* head) {
        int index = 0;
        for(ListNode* curr = head; curr; curr = curr->next){
            while(!nextLarge.empty() && curr->val > nextLarge.top().first){
                answer[nextLarge.top().second] = curr->val;
                nextLarge.pop();
            }
            nextLarge.push({curr->val, index});
            answer.push_back(0);
            index++;
        }
        return answer;
    }
};