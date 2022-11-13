// @Author: KING-SEN
// 1 last try

class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int n = sentence.size(), pos = 0;
        unordered_map<int, int> seen;
        for (int i = 0; i < rows; i++) {
            int curr_sum = 0, index = pos % n;
            if (seen.count(index)) {
                pos += seen[index]; 
            } else {
                int count = 0;
                while (curr_sum + sentence[pos % n].size() <= cols) {
                    curr_sum += sentence[pos % n].size() + 1;
                    pos++;
                    count++;
                }
                seen[index] = count;
            }
        }
        return pos / n;
    }
};

// Time: O(rows + cols)
// Space: O(1)