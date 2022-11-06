class Solution {
public:
    string orderlyQueue(string s, int k) {
        if (k == 1) {
            int len = s.size(), index = 0;
            string answer = s;
            s.append(s);
            while (index < len) {
                string smallest = s.substr(index, len);
                if (answer > smallest) {
                    answer = smallest;
                }
                index++;
            }
            return answer;
        }
        sort(s.begin(), s.end());
        return s;
    }
};