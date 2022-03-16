class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int pus = 0, pp = 0;
        while(pus < pushed.size()){
            while(pus < pushed.size() && pushed[pus] != popped[pp]){
                st.push(pushed[pus]);
                pus++;
            }
            if(pus < pushed.size() && pp < popped.size() && pushed[pus] == popped[pp]) pus++, pp++;
            while(!st.empty() && pp < popped.size() && st.top() == popped[pp]){
                pp++;
                st.pop();
            }
            if(pus == pushed.size() && pp < popped.size())
                return false;
        }
        return true;
    }
};