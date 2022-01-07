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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    vector<int> vt;
    int size;
    Solution(ListNode* head) {
        while(head){
            int item = head->val;
            vt.push_back(item);
            head = head->next;
        }
        size = vt.size();
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int rnd = rand() % size;
        return vt[rnd];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */