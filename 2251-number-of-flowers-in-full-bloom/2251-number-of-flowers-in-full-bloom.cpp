class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        int cnt = 0, len = persons.size();
        map<int, int> count, res;
        vector<int> answer(len, 0);
        count[0] = 0;
        for(auto flower : flowers){
            count[flower[0]]++;
            count[flower[1] + 1]--;
        }
        for(auto &it : count){
            cnt += it.second;
            it.second = cnt;
        }
        for(int i = 0; i < persons.size(); i++){
            auto pos = count.upper_bound(persons[i]); 
            answer[i] = prev(pos)->second;
        }
        return answer;
    }
};