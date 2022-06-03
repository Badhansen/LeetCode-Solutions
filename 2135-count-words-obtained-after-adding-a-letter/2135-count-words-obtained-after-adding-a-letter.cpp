class Solution {
private:
    unordered_map<int, bool> dict;
public:
    int getMask(string& word){
        int mask = 0, index;
        for(auto &c : word){
            index = c - 'a';
            mask |= (1 << index);
        }
        return mask;
    }
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        for(auto &word : startWords){
            int mask = getMask(word);
            for(int index = 0; index < 26; index++){
                int newMask = mask;
                if(!(mask & (1 << index))){
                    newMask |= (1 << index);
                    dict[newMask] = true;
                }
            }
        }
        int count = 0;
        for(auto &word : targetWords){
            int mask = getMask(word);
            if(dict.count(mask)){
                count++;
            }
        }
        return count;
    }
};
