class Solution {
public:
    string removeDuplicates(string s) {
        string res = "";
        for (char& c : s){
            if (res.size() && c == res.back()) {
                res.pop_back();
            }
            else {
                res.push_back(c);
            }
        }
        return res;
    }
};
/*
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for(int i = 0; i < s.size(); i++){
            if(!st.empty()){
                char ch = st.top();
                if(ch == s[i]) st.pop();
                else st.push(s[i]);
            }
            else{
                st.push(s[i]);
            }
        }
        string ans = "";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
*/
