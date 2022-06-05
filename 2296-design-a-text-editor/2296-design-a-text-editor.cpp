class TextEditor {
private:
    string _text;
    int pos;
public:
    TextEditor() {
        pos = 0;
    }
    
    void addText(string text) { // O(N)
        _text.insert(pos, text);
        pos += text.size();
    }
    
    int deleteText(int k) { // O(K * N)
        int count = 0;
        while(pos != 0 && count < k){ // O(N)
            _text.erase(pos - 1, 1);
            pos--;
            count++;
        }
        return count;
    }
    
    string cursorLeft(int k) { // O(K)
        pos = max(pos - k, 0);
        string res = "";
        for(int i = pos - 10; i < pos; i++){
            if(i >= 0) res += _text[i];
        }
        return res;
    }
    
    string cursorRight(int k) { // O(K)
        pos = min(pos + k, (int)_text.size());
        string res = "";
        for(int i = pos - 10; i < pos; i++){
            if(i >= 0) res += _text[i];
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