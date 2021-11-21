/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    unordered_map<Node*, Node*> seen;
public:
    Node* copy(Node* node){
        if(!node) 
            return nullptr;
        if(seen.count(node))
            return seen[node];
        
        Node* root = new Node(node->val);
        seen[node] = root;
        
        for(auto n : node->neighbors){
            root->neighbors.push_back(copy(n));
        }
        
        return root;
    }
    Node* cloneGraph(Node* node) {
        return copy(node);
    }
};