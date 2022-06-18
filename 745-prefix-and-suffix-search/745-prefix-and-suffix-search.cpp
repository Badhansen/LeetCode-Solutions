class TrieNode{
public:
    int index;
	unordered_map<char, TrieNode*> next;
    TrieNode(){
        index = 0;
    }
};

class Trie {
public:
	TrieNode* root;
	Trie(){
		root = new TrieNode();
	}
	void insert(string str, int val){
		TrieNode* curr = root;
        curr->index = val;
		for(int i = 0; i < str.size(); i++){
			if(!curr->next.count(str[i])){
				curr->next[str[i]] = new TrieNode();
			}
			curr = curr->next[str[i]];
            curr->index = val;
		}
	}
};

class WordFilter {
private:
    Trie tree;
public:
	WordFilter(vector<string>& words) {
		for (int i = 0; i < words.size(); i++) {
            string s = words[i] + '$' + words[i];
            for(int j = 0; j <= words[i].size(); j++){
                string st = s.substr(j, s.size());
                tree.insert(st, i);
            }
		}
	}

	int f(string prefix, string suffix){
		TrieNode* curr = tree.root;
        string s = suffix + '$' + prefix;
		for(int i = 0; i < s.size(); i++){
			if(!curr->next.count(s[i])) return -1;
			curr = curr->next[s[i]];
		}
		return curr->index;
	}
};