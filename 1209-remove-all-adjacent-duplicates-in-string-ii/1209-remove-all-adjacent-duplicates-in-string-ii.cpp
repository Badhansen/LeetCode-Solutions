class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<int, int>> st;
        for(int i = 0; i < s.size(); i++){
            if(st.empty() || st.top().first != s[i]){
                st.push({s[i], 1});
            }
            else{
                int count = st.top().second + 1;
                st.pop();
                st.push({s[i], count});
            }
            if(st.top().second == k){
                st.pop();
            }
        }
        string ans;
        while(!st.empty()){
            auto top = st.top();
            st.pop();
            ans.append(string(top.second, top.first));
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};