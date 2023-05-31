bool ans = false;
class TrieNode{
public:
    int isEnd;
    unordered_map<int, TrieNode*> next;
    TrieNode(){
        isEnd = false;
    }
};
class Trie{
public:
    TrieNode *root;
    Trie(){
        root = new TrieNode();
    }
    void insert(string str){
        TrieNode* curr = root;
        for(int i = 0; i < str.size(); i++){
            int index = str[i] - 'a';
            if(curr->next[index] == NULL){
                curr->next[index] = new TrieNode();
            }
            curr = curr->next[index];
        }
        curr->isEnd = true;
    }
    bool search(TrieNode *root, string str, int pos){
        if(pos > str.size()) return false;
        if(root == NULL) return false;
        if(pos == str.size()){
            if(root->isEnd)
                return true;
            return false;
        }
        bool res = false;
        if(str[pos] == '.'){
            for(int j = 0; j < 26; j++){
                if(root->next[j]) res |= search(root->next[j], str, pos + 1);
                if (res) return true;
            }
        }
        else{
            int index = str[pos] - 'a';
            res |= search(root->next[index], str, pos + 1);
            if (res) return true;
        }
        return res;
    }
    void print(TrieNode* root, char *st, int pos){
        if(root == NULL) return;
        if(root->isEnd){
            cout << st << endl;
        }
        else{
            for(int i = 0; i < 26; i++){
                if(root->next[i]){
                    st[pos] = 'a' + i;
                    print(root->next[i], st, pos + 1);
                }
            }
        }
    }
};
class WordDictionary {
private:
    Trie* root;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new Trie();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        root->insert(word);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return root->search(root->root, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */