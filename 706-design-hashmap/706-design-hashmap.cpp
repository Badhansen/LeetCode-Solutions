//@Author: KING-SEN
class Trie{
public:
    int value;
    unordered_map<int, Trie*> children;
    Trie(){
        value = -1;
    }
};
class MyHashMap {
private:
    Trie* root;
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        root = new Trie;
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        Trie* current = root;
        while(key){
            int rem = key % 10;
            if(current->children.find(rem) == current->children.end()){
                current->children[rem] = new Trie();
            }
            key /= 10;
            current = current->children[rem];
        }
        current->value = value;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        Trie* current = root;
        while(key){
            int rem = key % 10;
            if(current->children.find(rem) == current->children.end()){
                return -1;
            }
            key /= 10;
            current = current->children[rem];
        }
        return current->value;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        Trie* current = root;
        while(key){
            int rem = key % 10;
            key /= 10;
            if(current->children.find(rem) == current->children.end()){
                return;
            }
            current = current->children[rem];
        }
        current->value = -1;
    }
    
    void deleteAll(Trie* root) {
        for(auto [key, value] : root->children) {
            deleteAll(value);
        }
        delete root;
    }

    ~MyHashMap() {
        deleteAll(root);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */