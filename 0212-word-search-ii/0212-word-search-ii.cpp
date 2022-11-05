class Trie {
private:
    unordered_map<char, Trie*> children;
    bool isEnd;
    string word;
public:
    Trie() {
        isEnd = false;
    }
    Trie* GetChild(char item) {
        return this->children[item];
    }
    void NewChild(char item) {
        this->children[item] = new Trie();
    }
    bool HasChild(char item) {
        if (this->children.count(item)) {
            return true;
        }
        return false;
    }
    bool GetEnd() {
        return this->isEnd;
    }
    void SetEnd(bool value) {
        this->isEnd = value;
    }
    void SetWord(string value) {
        this->word = value;
    }
    string GetWord() {
        return this->word;
    }
};

class Solution {
private:
    Trie* root = new Trie();
public:
    void AddWord(std::string word) {
        Trie* current = root;
        for (auto w : word) {
            if (!current->HasChild(w)) {
                current->NewChild(w);
            }
            current = current->GetChild(w);
        }
        current->SetEnd(true);
        current->SetWord(word);
    }
    void Dfs(int r, int c, int rows, int cols, Trie* root, vector<vector<char>>& board, vector<string>& answer) {
        if (r < 0 || r >= rows || c < 0 || c >= cols || board[r][c] == '#' || !root->HasChild(board[r][c])) {
            return;
        }
        char item = board[r][c];
        board[r][c] = '#';
        root = root->GetChild(item);
        if (root->GetEnd()) {
            answer.push_back(root->GetWord());
            root->SetEnd(false);
        }
        Dfs(r - 1, c, rows, cols, root, board, answer);
        Dfs(r + 1, c, rows, cols, root, board, answer);
        Dfs(r, c - 1, rows, cols, root, board, answer);
        Dfs(r, c + 1, rows, cols, root, board, answer);
        board[r][c] = item;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for (auto w : words) {
            AddWord(w);
        }
        int rows = board.size();
        int cols = board[0].size();
        vector<string> answer;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                Dfs(i, j, rows, cols, root, board, answer);
            }
        }
        return answer;
    }
};