// @author: KING-SEN
// Programming Language Used: C++

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> word_map;
        unordered_set<string> discovered;
        queue<pair<string, int>> que;
        for (auto w : wordList) {
            word_map.insert(w);
        }
        que.push({beginWord, 0});
        discovered.insert(beginWord);
        
        while(!que.empty()){
            auto node = que.front();
            que.pop();
            string source = node.first;
            int distance = node.second;
            if(source == endWord) {
                return distance + 1;
            }
            for (int i = 0; i < source.size(); i++) {
                char item = source[i];
                for (char j = 'a'; j <= 'z'; j++) {
                    if (source[i] != j) {
                        source[i] = j;
                        if (word_map.count(source)) {
                            if (!discovered.count(source)) {
                                discovered.insert(source);
                                que.push({source, distance + 1});
                            }
                        }
                    }
                }
                source[i] = item;
            }
        }
        return 0;
    }
};

