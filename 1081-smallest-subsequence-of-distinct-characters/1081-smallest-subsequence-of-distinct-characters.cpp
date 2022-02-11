class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> lastIndex(26, 0);
        vector<bool> seen(26, false);
        int len = s.size();
        for(int i = 0; i < len; i++){
            lastIndex[s[i] - 'a'] = i;
        }
        stack<char> result;
        for(int i = 0; i < len; i++){
            int id = s[i] - 'a';
            if(seen[id]) continue;
            while(!result.empty() && result.top() > s[i] && lastIndex[result.top() - 'a'] > i){
                seen[result.top() - 'a'] = false;
                result.pop();
            }
            result.push(s[i]);
            seen[s[i] - 'a'] = true;
        }
        string answer;
        while(!result.empty()){
            answer.push_back(result.top());
            result.pop();
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }
};