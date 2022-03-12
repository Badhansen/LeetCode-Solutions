/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> seen;
        Node* curr = head;
        
        while(curr){
            Node* temp = new Node(curr->val);
            seen[curr] = temp;
            curr = curr->next;
        }
        
        curr = head;
        
        while(curr){
            seen[curr]->next = seen[curr->next];
            seen[curr]->random = seen[curr->random];
            curr = curr->next;
        }
        
        return seen[head];
    }
};