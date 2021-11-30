static auto _ = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

class UnionFind {
private:
    struct Node {
        int parent;
        int rank;
    };
    vector<Node> nodes;
    
public:
    UnionFind(int n) : nodes(n) {}
    
    void Init(int i) {
        nodes[i].parent = i;
    }
    
    int FindRoot(int i) {
        if (nodes[i].parent == i) {
            return i;
        }
        return nodes[i].parent = FindRoot(nodes[i].parent);
    }
    
    void Unify(int i, int j) {
        i = FindRoot(i);
        j = FindRoot(j);
        if (i == j) {
            return;
        }
        if (nodes[i].rank < nodes[j].rank) {
            nodes[i].parent = j;
        } else if (nodes[j].rank < nodes[i].rank) {
            nodes[j].parent = i;
        } else {
            nodes[j].parent = i;
            ++nodes[i].rank;
        }
    }
};

struct Email {
    static hash<string> hasher;
    
    Email(string* str) : s(str) {
        h = hasher(*s);
    }
    
    string* s;
    size_t  h;
};

struct EmailHasher {
    inline size_t operator()(const Email& email) const {
        return email.h;
    }
};

struct EmailEqual {
    inline bool operator() (const Email& a, const Email& b) const {
        return *a.s == *b.s;
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        UnionFind union_find(accounts.size());
        unordered_map<Email, int, EmailHasher, EmailEqual> email_to_acc;
        for (int i = 0; i < accounts.size(); ++i) {
            union_find.Init(i);
            for (int j = 1; j < accounts[i].size(); ++j) {
                if (auto it = email_to_acc.find(&accounts[i][j]); it != email_to_acc.end()) {
                    union_find.Unify(it->second, i);
                } else {
                    email_to_acc.emplace(&accounts[i][j], i);
                }
            }
        }
        unordered_map<int, vector<string*>> result_map;
        for (auto& [email, acc]: email_to_acc) {
            int r = union_find.FindRoot(acc);
            if (auto it = result_map.find(r); it != result_map.end()) {
                it->second.emplace_back(email.s);
            } else {
                result_map[r] = {&accounts[acc][0], email.s};
            }
        }
        vector<vector<string>> result;
        for (auto& [i, emails] : result_map) {
            auto& row = result.emplace_back();
            for (int j = 0; j < emails.size(); ++j) {
                row.emplace_back(move(*emails[j]));
            }
            sort(row.begin() + 1, row.end());
        }
        return result;
    }
};