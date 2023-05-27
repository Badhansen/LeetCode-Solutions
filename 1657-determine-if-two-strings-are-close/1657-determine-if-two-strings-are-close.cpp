// @Author: KING-SEN

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> count1(26, 0), count2(26, 0);
        set<char> set1, set2;
        for (auto w : word1){
            count1[w - 'a']++;
            set1.insert(w);
        }
        for (auto w : word2) {
            count2[w - 'a']++;
            set2.insert(w);
        }
        sort(count1.begin(), count1.end());
        sort(count2.begin(), count2.end());
        if (set1 == set2 && count1 == count2) {
            return true;
        }
        return false;
    }
};