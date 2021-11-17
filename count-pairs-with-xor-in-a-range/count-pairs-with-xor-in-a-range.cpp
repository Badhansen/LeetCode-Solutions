#define MAX_LEVEL 15
#define MAX_CHILD 2

class TrieNode{
private:
    int count;
    vector<TrieNode*> children;
public:
    TrieNode() : count(0), children(MAX_CHILD, nullptr){}
    
    ~TrieNode(){
        for(auto &child : children){
            delete(child);
        }
    }
    
    void insert(int number){
        TrieNode* root = this;
        for(int i = MAX_LEVEL; i >= 0; i--){
            bool bit = number & (1 << i);
            
            if(!root->children[bit]){
                root->children[bit] = new TrieNode();
            }
            
            root = root->children[bit];
            root->count++;
        }
    }
    
    int countSmallerPairs(int number, int upperLimit){
        TrieNode* root = this;
        int result = 0;
        
        for(int i = MAX_LEVEL; i >= 0 && root; i--){
            bool a = number & (1 << i);
            bool b = upperLimit & (1 << i);
            
            if(!b){
                root = root->children[a];
            }
            else{
                if(root->children[a]){
                    result += root->children[a]->count;
                }
                root = root->children[1 - a];
            }
        }
        
        return result;
    }    
};

class Solution {
public:
    int countPairs(vector<int>& nums, int low, int high) {
        int result = 0;
        TrieNode* root = new TrieNode();
        
        for(auto n : nums){
            result += root->countSmallerPairs(n, high + 1) - root->countSmallerPairs(n, low);
            root->insert(n);
        }
        
        return result;
    }
};