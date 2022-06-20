// @Author: KING-SEN
// 1 last try

class Solution {
private:
    struct TrieNode{ 
        TrieNode *children[26];
        bool isEndOfWord; 
    };
    string ans;
public:
    TrieNode *getNode(void) 
    { 
        TrieNode *pNode =  new TrieNode; 
        pNode->isEndOfWord = false; 
        for(int i = 0; i < 26; i++) 
            pNode->children[i] = NULL; 
        return pNode; 
    } 
    void insert(TrieNode *root, string key){ 
        TrieNode *pCrawl = root; 
        for (int i = 0; i < key.length(); i++) { 
            int index = key[i] - 'a'; 
            if (!pCrawl->children[index]) 
                pCrawl->children[index] = getNode(); 

            pCrawl = pCrawl->children[index]; 
        } 
        pCrawl->isEndOfWord = true; 
    } 
    void dfs(TrieNode* root, string path){
        TrieNode *pCrawl = root;
        if(pCrawl->isEndOfWord){
            if(ans.size() < path.size()){
                ans = path;
            }
        }
        for(int i = 0; i < 26; i++){
            if(pCrawl->children[i] && pCrawl->isEndOfWord){
                path.push_back('a' + i);
                dfs(pCrawl->children[i], path);
                path.pop_back();
            }
        }
    }
    
    string longestWord(vector<string>& words) {
        TrieNode *root = getNode();
        for(int i = 0; i < words.size(); i++){
            insert(root, words[i]); 
        }
        for(int i = 0; i < 26; i++){
            if(root->children[i] && root->children[i]->isEndOfWord){
                string path;
                path.push_back('a' + i);
                dfs(root->children[i], path);
            }
        }       
        return ans;
    }
};


// Time: O(Sum of words len)
// Space: O(Sum of words)

/*
// 1 last try

class Solution {
private:
    unordered_map<string, bool> seen;
public:
    string longestWord(vector<string>& words) {
        string answer;
        for(auto word : words){
            seen[word] = true;
        }
        for(auto word : words){
            int count = 0;
            string curr;
            for(auto c : word){
                curr += c;
                if(seen.count(curr)) count++;
                else break;
            }
            if(count == word.size()){
                if(answer.size() == word.size()) answer = min(answer, word);
                if(answer.size() < word.size()) answer = word;
            }
        }
        return answer;
    }
};
// Time: O(N * L), N = length of the array, L = maximum string length
// Space: O(N)
*/