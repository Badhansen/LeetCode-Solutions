class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<int, int>> st;
        for(int i = 0; i < s.size(); i++){
            if(st.empty() || st.top().first != s[i]){
                st.push({s[i], 1});
            }
            else{
                st.top().second++;
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