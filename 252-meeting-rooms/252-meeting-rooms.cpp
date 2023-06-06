// @Author: KING-SEN
class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return true;
        }
        map<int, int> seen;
        
        for(auto &el : intervals){
            seen[el[0]]++;
            seen[el[1]]--;
        }
        
        int count = 0, answer = 0;
        
        for(auto &el : seen){
            answer = max(answer, count += el.second);
        }
        
        return answer == 1 ? true : false;
    }
};
/*
// @Author: KING-SEN
class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if(!intervals.size()) {
            return true;
        }
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b){
            return a[1] < b[1];
        });
        for (int i = 0; i < intervals.size() - 1; i++) {
            if (intervals[i][1] > intervals[i + 1][0]) {
                return false;
            }
        }
        return true;
    }
};
*/