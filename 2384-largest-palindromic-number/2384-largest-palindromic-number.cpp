class Solution {
public:
    string largestPalindromic(string num) {
        vector<int> count(10, 0);
        priority_queue<pair<int, int>> que;
        priority_queue<int> single;
        for (auto n : num) {
            count[n - '0']++;
        }
        for (int i = 0; i < 10; i++) {
            if (count[i]) {
                que.push({i, count[i]});
            }
        }
        string res = "";
        while (!que.empty()) {
            auto node = que.top();
            que.pop();
            if (node.second > 1) {
                if (res.empty() && node.first == 0) {
                    continue;
                }
                res += to_string(node.first);
                node.second -= 2;
                if (node.second) {
                    que.push(node);
                }
            } else {
                single.push(node.first);
            }
        }
        
        string rev = res;
        reverse(rev.begin(), rev.end());
        if (single.size()) {
            res += to_string(single.top());
            res.append(rev);
        } else {
            res.append(rev);
        }
        return res.empty() ? "0" : res;
    }
};