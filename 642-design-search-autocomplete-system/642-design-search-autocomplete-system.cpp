// @Author: KING-SEN
// 1 last try

class Trie{
private:
    unordered_map<char, Trie*> children;
    unordered_map<string, int> counts;
public:
    Trie(){
    }
    void insert(string& word, int val){
        Trie *curr = this;
        for(int i = 0; i < word.size(); i++){
            if(!curr->children.count(word[i])){
                curr->children[word[i]] = new Trie();
            }
            curr = curr->children[word[i]]; 
            curr->counts[word] += val;
        }
    }
    Trie* find(string& word){
        Trie *curr = this;
        for(int i = 0; i < word.size(); i++){
            if(!curr->children.count(word[i]))
                return NULL;
            curr = curr->children[word[i]]; 
        }
        return curr;
    }
    unordered_map<string, int> getCounts(Trie* curr){
        return curr->counts;
    }
    ~Trie(){
        children.clear();
    }
};
class AutocompleteSystem {
private:
    struct Node{
        int time;
        string word;
        Node(int t, string w){
            time = t;
            word = w;
        }
        bool operator < (const Node& x) const {
            if(time == x.time){
                return word > x.word;
            }
            return time < x.time;
        }
    };
    Trie* root;
    string stream;
public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        root = new Trie();
        int n = sentences.size();
        for(int i = 0; i < n; i++){
            root->insert(sentences[i], times[i]);
        }
    }
    
    vector<string> input(char c) {
        vector<string> ans;
        if(c == '#'){
            root->insert(stream, 1);
            stream.clear();
        }
        else{
            stream.push_back(c);
            Trie* curr = root->find(stream);
            unordered_map<string, int> counts;
            if(curr != NULL) counts = curr->getCounts(curr);
            priority_queue<Node> que;
            for(auto count : counts){
                que.push(Node(count.second, count.first));
            }
            int count = 3;
            while(!que.empty() && count){
                ans.push_back(que.top().word);
                que.pop();
                count--;
            }
        }
        return ans;
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */