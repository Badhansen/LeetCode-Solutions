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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> temp, ans;
        while (head) {
            temp.push_back(head);
            head = head->next;
        }
        int n = temp.size();
        int d = n / k;
        int r = n % k;
        int idx = 0;
        while (k) {
            if (idx < n) {
                ans.push_back(temp[idx]);
            } else {
                ans.push_back(NULL);
            }
            int i = d;
            while (i) {
                if (idx < n) {
                    idx++;
                }
                i--;
            }
            if (r) {
                if (idx < n) {
                    temp[idx]->next = NULL;
                    idx++;
                }
                r--;
            } else {
                if (idx < n) {
                    temp[idx - 1]->next = NULL;
                }
            }
            k--;
        }
        return ans;
    }
};