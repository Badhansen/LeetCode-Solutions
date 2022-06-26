// @Author: KING-SEN
// 1 last try

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

class Trie{
private:
    unordered_map<char, Trie*> children;
    bool isEnd;
    int times; 
public:
    Trie(){
        this->isEnd = false;
        this->times = 0;
    }
    void insert(string& word, int val){
        Trie *curr = this;
        for(int i = 0; i < word.size(); i++){
            if(curr->children[word[i]] == NULL){
                curr->children[word[i]] = new Trie();
            }
            curr = curr->children[word[i]];
        }
        curr->isEnd = true;
        curr->times += val;
    }
    void dfs(Trie* curr, string& path, priority_queue<Node>& que){
        if(!curr) return;
        if(curr->isEnd) que.push(Node(curr->times, path));
        char c = ' ';
        for(int i = 0; i < 27; i++){
            if(i == 26) c = ' ';
            else c = 'a' + i;
            path.push_back(c);
            dfs(curr->children[c], path, que);
            path.pop_back();
        }
    }
    vector<string> find(string word){
        Trie *curr = this;
        for(int i = 0; i < word.size(); i++){
            if(curr->children[word[i]] == NULL)
                return {};
            curr = curr->children[word[i]]; 
        }
        priority_queue<Node> que;
        string path = word;
        dfs(curr, path, que);
        vector<string> ans;
        int count = 3;
        while(!que.empty() && count){
            ans.push_back(que.top().word);
            que.pop();
            count--;
        }
        return ans;
    }
    ~Trie(){
        children.clear();
    }
};
class AutocompleteSystem {
private:
    Trie* root;
    string stream = "";
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
            stream += c;
            ans = root->find(stream);
        }
        return ans;
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */
