class RangeFreqQuery {
private:
    map<int, vector<int>> _indexes;
public:
    RangeFreqQuery(vector<int>& arr) {
        for (int i = 0; i < arr.size(); i++) {
            _indexes[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int value) {
        int left_index = lower_bound(_indexes[value].begin(), _indexes[value].end(), left) - _indexes[value].begin();
        int right_index = upper_bound(_indexes[value].begin(), _indexes[value].end(), right) - _indexes[value].begin();
        return right_index - left_index;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */