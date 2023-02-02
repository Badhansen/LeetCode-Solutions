class Solution {
public:
    bool isSorted(vector<int>& seen, string& first, string &second){
        int firstLen = first.size(), secondLen = second.size();
        
        for(int i = 0; i < firstLen && i < secondLen; i++){
            if(first[i] != second[i]){
                return seen[first[i] - 'a'] > seen[second[i] - 'a'];
            }
        }
        return firstLen > secondLen;
    }
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> seen(26, 0);
    
        for(int i = 0; i < order.size(); i++){
            seen[order[i] - 'a'] = i;
        }
        
        for(int i = 1; i < words.size(); i++){
            if(isSorted(seen, words[i - 1], words[i])){
                return false;
            }
        }
        return true;
    }
};