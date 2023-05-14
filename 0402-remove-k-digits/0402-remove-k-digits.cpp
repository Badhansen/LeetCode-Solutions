class Solution {
public:
    string removeKdigits(string num, int k) {
        deque<int> que;
        for (int i = 0; i < num.size(); i++) {
            while (!que.empty() && k && que.back() > num[i] - '0') {
                k--;
                que.pop_back();
            }
            
            que.push_back(num[i] - '0');
            
            if (k == 0) {
                i++;
                while (i < num.size()) {
                    que.push_back(num[i] - '0');
                    i++;
                }
                break;
            }
        }
        string answer;
        for (int i = 0; i < que.size() - k; i++) {
            if (answer.size() == 0 && que.at(i) == 0) {
                continue;
            }
            answer.push_back('0' + que.at(i));
        }
        if (answer.size() == 0) {
            return "0";
        } 
        return answer;
    }
};