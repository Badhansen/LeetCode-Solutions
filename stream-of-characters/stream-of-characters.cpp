//@Author: KING-SEN
// Programming Language Used: C++

class Trie{
private:
    unordered_map<char, Trie*> children;
    bool isEnd;
public:
    Trie(){
        isEnd = false;
    }
    void insert(string& word){
        Trie *curr = this;
        for(int i = word.size() - 1; i >= 0; i--){
            if(!curr->children.count(word[i]))
                curr->children[word[i]] = new Trie();
            curr = curr->children[word[i]]; 
        }
        curr->isEnd = true;
    }
    bool find(string& word){
        Trie *curr = this;
        for(int i = word.size() - 1; i >= 0; i--){
            if(!curr->children.count(word[i]))
                return false;
    
            curr = curr->children[word[i]]; 
            
            if(curr->isEnd) 
                return true;
        }
        return curr->isEnd;
    }
    ~Trie(){
        children.clear();
    }
};
class StreamChecker {
private:
    Trie *root = new Trie();
    string word;
public:
    StreamChecker(vector<string>& words) {
        for(auto &w : words){
            root->insert(w);
        }
    }
    
    bool query(char letter) {
        word.push_back(letter);
        return root->find(word);
    }
};

// Time Complexity: O(N * M)
// Space Complexity: O(N * M)