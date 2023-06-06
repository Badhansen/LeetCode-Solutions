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