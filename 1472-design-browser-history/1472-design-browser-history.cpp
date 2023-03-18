class DoublyList{    
public:
    string data;
    DoublyList *prev, *next;
    DoublyList(string url){
        this->data = url;
        this->prev = this->next = NULL;
    }
};
class BrowserHistory {
private:
    DoublyList *root;
public:
    BrowserHistory(string homepage) {
        root = new DoublyList(homepage);
    }
    
    void visit(string url) {
        DoublyList *temp = new DoublyList(url);
        temp->prev = root;
        root->next = temp;
        root = temp;
    }
    
    string back(int steps) {
        while(root->prev != NULL && steps){
            root = root->prev;
            steps--;
        }
        return root->data;
    }
    
    string forward(int steps) {
        while(root->next != NULL && steps){
            root = root->next;
            steps--;
        }
        return root->data;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */