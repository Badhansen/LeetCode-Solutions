class TextEditor {
private:
    stack<char> left, right;
public:
    TextEditor() {
        // pass
    }
    
    void addText(string text) { // O(N)
       for(auto c : text){
           left.push(c);
       }
    }
    
    int deleteText(int k) { // O(K)
        int count = 0;
        while(!left.empty() && k){ 
            left.pop();
            count++, k--;
        }
        return count;
    }
    
    string cursorLeft(int k) { // O(K)
        while(!left.empty() && k){
            char c = left.top();
            left.pop();
            right.push(c);
            k--;
        }
        return getString();
    }
    
    string cursorRight(int k) { // O(K)
        while(!right.empty() && k){
            char c = right.top();
            right.pop();
            left.push(c);
            k--;
        }
        return getString();
    }
    string getString(){
        string res = "";
        int count = 10;
        while(!left.empty() && count){
            char c = left.top();
            left.pop();
            res += c;
            count--;
        }
        reverse(res.begin(), res.end());
        for(int i = 0; i < res.size(); i++){
            left.push(res[i]);
        }
        return res;
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */