class CountIntervals {
private:
    set<pair<int, int>> st;
    int sum;
public:
    CountIntervals() {
        sum = 0;
    }
    
    void add(int left, int right) {
        auto it = st.upper_bound({left, INT_MIN});
        
        if(it != st.begin() && (--it)->second < left){
            it++;
        } 

        while(it != st.end() && it->first <= right){
            left = min(left, it->first);
            right = max(right, it->second);
            
            sum -= (it->second - it->first + 1);
            it = st.erase(it);
        }
        
        sum += (right - left + 1);
        st.insert({left, right});
    }
    
    int count() {
        return sum;
    }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */