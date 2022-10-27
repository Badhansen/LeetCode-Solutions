class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int n  = spells.size(), m = potions.size();
        vector<int> answer;
        for(auto s : spells){
            long long div = success / s;
            if (success % s != 0) div++;
            int count = lower_bound(potions.begin(), potions.end(), div) - potions.begin();
            answer.push_back(m - count);
        }
        return answer;
    }
};
/*
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int length = potions.size();
        vector<int> answer;
        for (auto s : spells) {
            long long div = (success - 1) / s;
            int index = upper_bound(potions.begin(), potions.end(), div) - potions.begin();
            answer.push_back(length - index);
        }
        return answer;
    }
};
*/