class Solution {
private:
    unordered_map<string, int> maps;
    int w_size, length;
public:
    bool IsExist(int index, string& s) {
        int w_count = 0;
        unordered_map<string, int> remaining = maps;
        for (int i = index; i < index + w_size; i += length) {
            string src = s.substr(i, length);
            if (remaining[src] > 0) {
                remaining[src]--;
                w_count++;
            } else {
                break;
            }
        }
        return w_count == w_size / length;
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.size();
        w_size = 0, length = words[0].size();
        vector<int> result;
        for (auto word : words) {
            w_size += word.size();
            maps[word]++;
        }
        for (int i = 0; i < n - w_size + 1; i++) {
            if (IsExist(i, s)) {
                result.push_back(i);
            }
        }
        return result;
    }
};