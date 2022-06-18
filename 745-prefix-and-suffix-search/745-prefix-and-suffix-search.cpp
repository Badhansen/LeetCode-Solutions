class TrieNode {
public:
	TrieNode* next[27];
	int index;
	TrieNode() {
		for (int i = 0; i < 27; i++) {
			next[i] = NULL;
		}
		index = 0;
	}
};
class Trie {
public:
	TrieNode* root;
	Trie() {
		root = new TrieNode();
	}
	void insert(string str, int val) {
		TrieNode* curr = root;
        curr->index = val;
		for (int i = 0; i < str.size(); i++) {
            int id;
            if(str[i] == '$') id = 26;
            else id = str[i] - 'a';
            
			if (curr->next[id] == NULL) {
				curr->next[id] = new TrieNode();
			}
			curr = curr->next[id];
            curr->index = val;
		}
	}
};
class WordFilter {
public:
	Trie tr;
	WordFilter(vector<string>& words) {
		for (int i = 0; i < words.size(); i++) {
            string s = words[i] + '$' + words[i];
            for(int j = 0; j <= words[i].size(); j++){
                string st = s.substr(j, s.size());
                tr.insert(st, i);
            }
		}
	}

	int f(string prefix, string suffix) {
		TrieNode* curr = tr.root;
        string s = suffix + '$' + prefix;
		for (int i = 0; i < s.size(); i++) {
            int id;
            if(s[i] == '$') id = 26;
            else id = s[i] - 'a';
            
			if (curr->next[id] == NULL) return -1;
			curr = curr->next[id];
		}
		return curr->index;
	}
};