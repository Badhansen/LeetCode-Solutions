class SummaryRanges {
private:
    set<pair<int, int>> st;
public:
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        int start = val, end = val;
        auto it = st.lower_bound({val, val});
        
        if(it != st.begin() && (--it)->second + 1 < val){
            it++;
        }
        while(it != st.end() && val + 1 >= it->first && val - 1 <= it->second){
            start = min(start, it->first);
            end = max(end, it->second);
            it = st.erase(it);
        }
        st.insert({start, end});
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        for(auto it : st){
            ans.push_back({it.first, it.second});
        }
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */