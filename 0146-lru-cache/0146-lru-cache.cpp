class Node {
public:
    int key, value;
    Node* next, *prev;
    Node(int key, int value) {
        this->key = key;
        this->value = value;
        next = prev = NULL;
    }
};
class LRUCache {
private:
    Node* head, *tail;
    int capacity;
    unordered_map<int, Node*> cache;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    void add(Node* currNode) {
        Node* nextNode = head->next;
        currNode->next = nextNode;
        nextNode->prev = currNode;
        currNode->prev = head;
        head->next = currNode;
        cache[currNode->key] = currNode;
    }
    void remove(Node* currNode) {
        Node* nextNode = currNode->next;
        Node* prevNode = currNode->prev;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        cache.erase(currNode->key);
    }
    int get(int key) {
        if (cache.find(key) != cache.end()) {
            Node* currNode = cache[key];
            remove(currNode);
            add(currNode);
            return currNode->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            remove(cache[key]);
        }
        if (cache.size() == capacity) {
            remove(tail->prev);
        }
        Node* newNode = new Node(key, value);
        add(newNode);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */