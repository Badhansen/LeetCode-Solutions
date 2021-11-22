class TimeMap {
private:
    unordered_map<string, map<int, string>> memo;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        memo[key].insert({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto it = memo[key].upper_bound(timestamp);
        return it == memo[key].begin() ? "" : prev(it)->second; 
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */