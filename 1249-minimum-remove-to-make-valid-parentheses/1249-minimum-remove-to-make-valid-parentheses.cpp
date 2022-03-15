class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        vector<int> dp(s.size(), 0);
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ')'){
                if(st.size() > 0) st.pop();
                else{
                    dp[i] = 1;
                }
            }
            else if(s[i] == '('){
                st.push(i);
            }
        }
        while(!st.empty()){
            int i = st.top();
            dp[i] = 1;
            st.pop();
        }
        string str;
        for(int i = 0; i < s.size(); i++){
            if(!dp[i]){
                str.push_back(s[i]);
            }
        }
        return str;
    }
};