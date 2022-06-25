class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        stack<char> st;
        for(auto el : s){
            if(el == '(') st.push('(');
            else if(el == ')'){
                ans = max(ans, (int)st.size());
                st.pop();
            }
        }
        return ans;
    }
};