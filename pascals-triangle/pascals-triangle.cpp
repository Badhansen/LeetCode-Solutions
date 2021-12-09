class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> answer;
        for(int i = 1; i <= numRows; i++){
            vector<int> value(i);
            value[0] = 1;
            value[i - 1] = 1;
            for(int j = 1; j < i - 1; j++){
                value[j] = answer[i - 2][j - 1] + answer[i - 2][j];
            }
            answer.push_back(value);
        }
        return answer;
    }
};