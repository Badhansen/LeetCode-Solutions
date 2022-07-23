class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> memo;
public:
    TimeMap() {
        memo.clear();
    }
    void set(string key, string value, int timestamp) {
        memo[key].push_back({timestamp, value});
    }
    string get(string key, int timestamp) {
        auto it = upper_bound(memo[key].begin(), memo[key].end(), pair<int, string>(timestamp, ""), [](
            const pair<int, string>& a, const pair<int, string>& b){
            return a.first < b.first;   
        });
        return it == memo[key].begin() ? "" : prev(it)->second; 
    }
};

/*
    Assuming "n" is the number of set operations, and "m" is the number of get operations:

    Time Complexity:
    Set: O(1) single operation, and total O(n).
    Note: assuing timestamps are only increasing. If not, it's O(n log n).
    Get: O(log n) for a single operation, and total O(m log n).
    Space Complexity: O(n) (assuming every { timestamp, value } is unique).
*/