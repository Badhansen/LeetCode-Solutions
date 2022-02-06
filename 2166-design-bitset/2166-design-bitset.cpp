class Bitset {
private:
    string curr, rev;
    int countBits;
public:
    Bitset(int size) {
        countBits = 0;
        curr.resize(size, '0');
        rev.resize(size, '1');
    }
    
    void fix(int idx) {
        if(curr[idx] == '0') countBits++;
        curr[idx] = '1';
        rev[idx] = '0';
    }
    
    void unfix(int idx) {
        if(curr[idx] == '1') countBits--;
        curr[idx] = '0';
        rev[idx] = '1';
    }
    
    void flip() {
        swap(curr, rev);
        int revCountBits = rev.size() - countBits;
        swap(revCountBits, countBits);
    }
    
    bool all() {
        return countBits == curr.size();
    }
    
    bool one() {
        return countBits > 0;
    }
    
    int count() {
        return countBits;
    }
    
    string toString() {
        return curr;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */