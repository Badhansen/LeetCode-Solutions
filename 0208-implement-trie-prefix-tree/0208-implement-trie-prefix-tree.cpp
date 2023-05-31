class Trie {
private:
    struct TrieNode {
        bool isend;
        unordered_map<char, TrieNode*> child;
        TrieNode() {
            isend = false;
        }
    };
public:
    TrieNode* root = new TrieNode();
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* curr = root;
        for (auto c : word){
            if (!curr->child.count(c)) {
                curr->child[c] = new TrieNode();
            }
            curr = curr->child[c];
        }
        curr->isend = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *curr = root;
        for (auto c : word){
            if (!curr->child.count(c)) {
                return false;
            }
            curr = curr->child[c];
        }
        if (curr->isend) {
            return true;
        }
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *curr = root;
        for (auto c : prefix){
            if (!curr->child.count(c)) {
                return false;
            }
            curr = curr->child[c];
        }
        if (curr == NULL) {
            return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */