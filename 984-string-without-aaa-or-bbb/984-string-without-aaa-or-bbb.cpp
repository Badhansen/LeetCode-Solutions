// @Author: KING-SEN

class Solution {
public:
    string strWithout3a3b(int a, int b) {
        priority_queue<pair<int, char>> qt;
        if(a != 0){
            qt.push({a, 'a'});
        }
        if(b != 0){
            qt.push({b, 'b'});
        }
        string ans;
        int size = 0;
        while(!qt.empty()){
            auto top = qt.top();
            qt.pop();
            if(size > 1 && ans[size - 1] == top.second && ans[size - 2] == top.second){
                if(qt.empty()){
                    return ans;
                }
                auto temp = qt.top();
                qt.pop();
                ans.push_back(temp.second);
                size++;
                temp.first--;
                if(temp.first > 0){
                    qt.push(temp);
                }
                qt.push(top);
            }
            else{
                ans.push_back(top.second);
                size++;
                top.first--;
                if(top.first > 0){
                    qt.push(top);
                }
            }
        }
        return ans;
    }
};