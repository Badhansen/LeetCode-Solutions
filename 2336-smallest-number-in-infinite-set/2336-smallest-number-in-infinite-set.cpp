class SmallestInfiniteSet {
 private:
    int next_number_;
    std::priority_queue<int, std::vector<int>, greater<int>> smallest_number_; 
    std::unordered_set<int> infinity_set_;
 public:
    SmallestInfiniteSet() {
        next_number_ = 1;
    }
    
    int popSmallest() {
        int smallest_value;
        if (!smallest_number_.empty()) {
            smallest_value = smallest_number_.top();
            smallest_number_.pop();
            infinity_set_.erase(smallest_value);
            return smallest_value;
        }
        smallest_value = next_number_;
        next_number_++;
        return smallest_value;
    }
    
    void addBack(int num) {
        if (num < next_number_ && !infinity_set_.count(num)){
            smallest_number_.push(num);
            infinity_set_.insert(num);
        }
    }
    
    ~SmallestInfiniteSet() {
        while (!smallest_number_.empty()) smallest_number_.pop();
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */