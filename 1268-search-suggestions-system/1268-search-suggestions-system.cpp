class Trie {
public:
    unordered_map<char, Trie*> children;
    vector<string> arr;
    Trie(){}
};

class Solution {
public:
    Trie *root;
    void insert(string product){
        Trie *curr = root;
        for(int i = 0; i < product.size(); i++){
            if(!curr->children.count(product[i])){
                curr->children[product[i]] = new Trie();
            }
            curr = curr->children[product[i]];
            curr->arr.push_back(product);
            sort(curr->arr.begin(), curr->arr.end());
            if(curr->arr.size() > 3){
                curr->arr.pop_back();
            }
        }
    }
    vector<string> search(string str){
        Trie *curr = root;
        vector<string> ans;
        for(int i = 0; i < str.size(); i++){
            if(!curr->children[str[i]]){
                return {};
            }
            curr = curr->children[str[i]];
            ans = curr->arr;
        }
        return ans;
    }
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> ans;
        vector<string> tempAns;
        root = new Trie();
        for(int i = 0; i <  products.size(); i++){
            insert(products[i]);
        }        
        for(int i = 0; i < searchWord.size(); i++){
            tempAns = search(searchWord.substr(0, i + 1));
            ans.push_back(tempAns);
        }
        return ans;
    }
};