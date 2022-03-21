class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last(26, 0);
        for(int i = 0; i < s.size(); i++){
            last[s[i] - 'a'] = i;
        }
        vector<int> answer;
        int maxId = 0, first = 0;
        for(int i = 0; i < s.size(); i++){
            maxId = max(maxId, last[s[i] - 'a']);
            if(maxId == i){
                answer.push_back(i - first + 1);
                first = i + 1;
            }
        }
        return answer;
    }
};