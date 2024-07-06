// @Author: KING-SEN
// Programming Language Used: C++

class Solution
{
public:
	static bool cmp(vector<int> a, vector<int> b) {
		if (a[0] == b[0]) return a[1] > b[1];
		return a[0] < b[0];
	}
	int minMeetingRooms(vector<vector < int>> &intervals) {
		sort(intervals.begin(), intervals.end());

		priority_queue<int, vector < int>, greater < int>> st;
		int answer = 0;
		for (auto i: intervals) {
			while (st.size() && st.top() <= i[0]) {
				st.pop();
			}
			st.push(i[1]);
			if (st.size() > answer) {
				answer = st.size();
			}
		}
		return answer;
	}
};

/*
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
*/
