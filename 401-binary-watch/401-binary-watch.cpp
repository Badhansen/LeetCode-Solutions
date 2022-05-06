class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<pair<int, int>> hours, minutes;
        vector<string> ans;
        for(int i = 0; i <= 11; i++){
            hours.push_back({i, __builtin_popcount(i)});
        }
        for(int i = 0; i <= 59; i++){
            minutes.push_back({i, __builtin_popcount(i)});
        }
        for(int i = 0; i < hours.size(); i++){
            for(int j = 0; j < minutes.size(); j++){
                if(hours[i].second + minutes[j].second == turnedOn){
                    string h = to_string(hours[i].first);
                    string m = to_string(minutes[j].first); 
                    m = m.size() == 1 ? "0" + m : m;
                    
                    ans.push_back(h + ":" + m);
                }
            }
        }
        return ans;
    }
};