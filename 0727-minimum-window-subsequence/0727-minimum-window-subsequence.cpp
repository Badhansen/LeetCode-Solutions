// @Author: KING-SEN

class Solution {
public:
    int findSubseq(string& s, string& t, int sid) {
        int tid = 0;
        while (sid < s.size()) {
            if (s[sid] == t[tid]) {
                tid++;
                if (tid == t.size()) {
                    break;
                }
            }
            sid++;
        }
        return tid == t.size() ? sid : -1;
    }
    int improveSubseq(string&s, string& t, int sid) {
        int tid = t.size() - 1;
        while (tid >= 0) {
            if (s[sid] == t[tid]) {
                tid--;
            }
            sid--;
        }
        return sid + 1;
    }
    string minWindow(string s1, string s2) {
        int minWindow = INT_MAX, index = 0, sindex = 0;
        while (index < s1.size()) {
            int end = findSubseq(s1, s2, index);
            if (end == -1) {
                break;
            }
            int start = improveSubseq(s1, s2, end);
            if (end - start + 1 < minWindow) {
                sindex = start;
                minWindow = end - start + 1;
            }
            index = start + 1;
        }
        return minWindow != INT_MAX ? s1.substr(sindex, minWindow) : "";
    }
};