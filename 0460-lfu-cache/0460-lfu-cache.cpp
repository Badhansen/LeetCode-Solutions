// @Author: KING-SEN

class Node{
public:
    int key, value, count;
    Node* next, *prev;
    Node(int key, int value){
        this->key = key;
        this->value = value;
        count = 1;
    }
};
class List{
public:
    int size;
    Node* head, *tail;
    List(){
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    void addFront(Node* node){
        Node* temp = head->next;
        node->next = temp;
        temp->prev = node;
        node->prev = head;
        head->next = node;
        size++;
    }
    void removeNode(Node* delNode){
        Node* delNext = delNode->next;
        Node* delPrev = delNode->prev;
        delPrev->next = delNext;
        delNext->prev = delPrev;
        size--;
    }
};
class LFUCache {
private:
    unordered_map<int, Node*> keyNode;
    unordered_map<int, List*> freqList;
    int maxCap, minFreq, currSize;
public:
    LFUCache(int capacity) {
        maxCap = capacity;
        minFreq = 0;
        currSize = 0;
    }
    void updateFreqList(Node* node){
        keyNode.erase(node->key);
        freqList[node->count]->removeNode(node);
        if(node->count == minFreq && freqList[node->count]->size == 0){
            minFreq++;
        }
        List* nextHFreqList = new List();
        if(freqList.find(node->count + 1) != freqList.end()){
            nextHFreqList = freqList[node->count + 1];
        }
        node->count += 1;
        nextHFreqList->addFront(node);
        freqList[node->count] = nextHFreqList;
        keyNode[node->key] = node;
    }
    int get(int key) {
        if(keyNode.find(key) != keyNode.end()){
            Node* node = keyNode[key];
            int value = node->value;
            updateFreqList(node);
            return value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(maxCap == 0){
            return;
        }
        if(keyNode.find(key) != keyNode.end()){
            Node* node = keyNode[key];
            node->value = value;
            updateFreqList(node);
        }
        else{
            if(currSize == maxCap){
                List* list = freqList[minFreq];
                keyNode.erase(list->tail->prev->key);
                freqList[minFreq]->removeNode(list->tail->prev);
                currSize--;
            }
            currSize++;
            minFreq = 1;
            List* listFreq = new List();
            if(freqList.find(minFreq) != freqList.end()){
                listFreq = freqList[minFreq];
            }
            Node* node = new Node(key, value);
            listFreq->addFront(node);
            keyNode[key] = node;
            freqList[minFreq] = listFreq;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */