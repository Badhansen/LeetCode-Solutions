class Trie {
public:
    bool isEnd;
    Trie *child[26];
    Trie() {
        isEnd = false;
        for(int i = 0; i < 26; i++){
            child[i] = NULL;
        }
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* temp = this;
        for(int i = 0; i < word.size(); i++){
            int id = word[i] - 'a';
            if(temp->child[id] == NULL)
                temp->child[id] = new Trie();
            temp = temp->child[id];
        }
        temp->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie *temp = this;
        for(int i = 0; i < word.size(); i++){
            int id = word[i] - 'a';
            if(temp->child[id] == NULL)
                return false;
            temp = temp->child[id];
        }
        if(temp->isEnd)
            return true;
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie *temp = this;
        for(int i = 0; i < prefix.size(); i++){
            int id = prefix[i] - 'a';
            if(temp->child[id] == NULL)
                return false;
            temp = temp->child[id];
        }
        if(temp == NULL)
            return false;
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