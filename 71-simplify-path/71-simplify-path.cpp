class Solution {
public:
    string simplifyPath(string path) {
        vector<string> folders;
        vector<string> res;
        stack<string> st;
        string folder;
        string ans = "";
        for(int i = 0; i < path.size(); i++){
            if(path[i] == '/'){
                folders.push_back(folder);
                folder = "";
            }
            else{
                folder.push_back(path[i]);
            }
        }
        if(folder != ""){
            folders.push_back(folder);
        }
        for(auto f : folders){
            if(f == "." || f.empty()){
                continue;
            }
            else if(f == ".."){
                if(!st.empty()){
                    st.pop();
                }
            }
            else{
                st.push(f);
            }
        }
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        for(auto &r : res){
            ans.append("/");
            ans.append(r);
        }
        return ans.size() == 0 ? "/" : ans;
    }
};