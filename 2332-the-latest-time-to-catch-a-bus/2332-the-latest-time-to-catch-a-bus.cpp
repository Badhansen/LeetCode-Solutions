// @Author: KING-SEN

class Solution {
 private:
    unordered_map<int, bool> seen;
 public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());
        for(auto p : passengers){
            seen[p] = true;
        }
        int p_id = 0;
        int last_passenger, cap = 0;
        for (auto &b : buses) {
            cap = 0;
            while (p_id < passengers.size() && passengers[p_id] <= b && cap < capacity) {
                last_passenger = passengers[p_id];
                cap++, p_id++;
            }
        }
        int answer;
        if (cap < capacity) {
            answer = buses[buses.size() - 1];
        } else {
            answer = last_passenger - 1;
        }
        while (seen.count(answer)) {
            answer--;
        }
        return answer;
    }
};
/*
[19,13,26,4,25,11,21]
[20,30,10]
[10,20,30]
  4 11 21
    12 25
    13 26
    19
  10
[4,11,13,19,21,25,26]
*/