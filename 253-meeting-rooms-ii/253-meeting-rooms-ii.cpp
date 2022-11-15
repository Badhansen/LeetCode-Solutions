// @Author: KING-SEN
// Programming Language Used: C++

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        map<int, int> seen;
        
        for(auto &el : intervals){
            seen[el[0]]++;
            seen[el[1]]--;
        }
        
        int count = 0, answer = 0;
        
        for(auto &el : seen){
            answer = max(answer, count += el.second);
        }
        
        return answer;
    }
};

// Time Complexity: O(N log N), where N is the number of elements in the intervals array
// Space Complexity: O(N), we have to store the answer in seen map
