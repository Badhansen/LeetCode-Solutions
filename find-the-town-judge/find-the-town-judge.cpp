class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        map<int, int> count;
        for(auto &num : trust){
            count[num[0]]--;
            count[num[1]]++;
        }
        if(N == 1)
            return 1;
        for(auto &[key, val] : count){
            if(val == N - 1)
                return key;
        }
        return -1;
    }
};